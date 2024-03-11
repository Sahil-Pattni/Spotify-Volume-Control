#include <Arduino.h>
//
// Created by Sahil Pattni on 2024-03-11.
//

#include "RefreshTokenGenerator.h"

WebServer server(80);

void init() {
    connectToWiFi();
    startServer();
}

void startServer() {
    sprintf(callbackURI, callbackURItemplate, callbackURIProtocol, ipAddress.toString().c_str(), callbackURIAddress);
    server.on("/", handleRoot);
    server.on("/callback/", handleCallback);
    server.onNotFound(handleNotFound);
    server.begin();
    Serial.println("HTTP server started");
}

void handleRoot()
{
    char webpage[800];
    sprintf(webpage, webpageTemplate, Credentials::clientID, callbackURI, scope);
    server.send(200, "text/html", webpage);
}

void handleCallback()
{
    String code = "";
    const char *refreshToken = NULL;
    for (uint8_t i = 0; i < server.args(); i++)
    {
        if (server.argName(i) == "code")
        {
            code = server.arg(i);
            refreshToken = spotify.requestAccessTokens(code.c_str(), callbackURI);
        }
    }

    if (refreshToken != NULL)
    {
        server.send(200, "text/plain", refreshToken);
    }
    else
    {
        server.send(404, "text/plain", "Failed to load token, check serial monitor");
    }
}

void handleNotFound()
{
    String message = "File Not Found\n\n";
    message += "URI: ";
    message += server.uri();
    message += "\nMethod: ";
    message += (server.method() == HTTP_GET) ? "GET" : "POST";
    message += "\nArguments: ";
    message += server.args();
    message += "\n";

    for (uint8_t i = 0; i < server.args(); i++)
    {
        message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
    }

    Serial.print(message);
    server.send(404, "text/plain", message);
}