//
// Created by Sahil Pattni on 2024-03-11.
//

#ifndef SPOTIFYVOLUME_BOOT_H
#define SPOTIFYVOLUME_BOOT_H

#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <SpotifyESP32.h>
#include <SpotifyESP32Cert.h>
#include <ArduinoJson.h>


void connectToWiFi();
void refreshToken(SpotifyESP32 spotifyEsp32);


#endif //SPOTIFYVOLUME_BOOT_H


