#include <Arduino.h>
//
// Created by Sahil Pattni on 2024-03-11.
//
#include "../include/Utils.h"


WiFiClientSecure client;
SpotifyArduino spotify(client, Credentials::clientID, Credentials::clientSecret);

int connectToWiFi() {
    WiFi.mode(WIFI_STA);
    WiFi.begin(Credentials::ssid, Credentials::password);
    Serial.println("");

    // Wait for connection
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }
    Serial.println("");
    Serial.print("Connected to ");
    Serial.println(Credentials::ssid);
    Serial.print("IP address: ");
    IPAddress ipAddress = WiFi.localIP();
    Serial.println(ipAddress);

    return 1;
}

void refreshToken(SpotifyESP32 spotifyObj) {
    Serial.println("Refreshing Access Tokens");
    if (!spotifyObj.refreshAccessToken())
    {
        Serial.println("Failed to get access tokens");
    }
}


