#include <Arduino.h>
#include <Utils.h>
//
// Created by Sahil Pattni on 2024-03-11.
//

#ifndef SPOTIFYVOLUME_REFRESHTOKENGENERATOR_H
#define SPOTIFYVOLUME_REFRESHTOKENGENERATOR_H

#include <WiFiClientSecure.h>

char callbackURItemplate[] = "%s%s%s";
char callbackURIProtocol[] = "http%3A%2F%2F"; // "http://"
char callbackURIAddress[] = "%2Fcallback%2F"; // "/callback/"
char callbackURI[100];
char scope[] = "user-read-playback-state%20user-modify-playback-state";

const char *webpageTemplate =
        R"(
<!DOCTYPE html>
<html>
  <head>
    <meta charset="utf-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0, maximum-scale=1.0, user-scalable=no" />
  </head>
  <body>
    <div>
     <a href="https://accounts.spotify.com/authorize?client_id=%s&response_type=code&redirect_uri=%s&scope=%s">spotify Auth</a>
    </div>
  </body>
</html>
)";


void init();
void startServer();
void handleRoot();
void handleCallback();
void handleNotFound();


#endif //SPOTIFYVOLUME_REFRESHTOKENGENERATOR_H
