#include <Arduino.h>
#include "../include/Utils.h"
#include "../include/RefreshTokenGenerator.h"

const int volumeKnobPin = 4;

void setup() {
    Serial.begin(115200);
    pinMode(volumeKnobPin, INPUT);

    connectToWiFi();
    #ifdef SPOTIFYVOLUME_REFRESHTOKENGENERATOR_H
        init();
    #endif
    client.setCACert(spotify_server_cert);

}

void loop() {
    #ifdef SPOTIFYVOLUME_REFRESHTOKENGENERATOR_H
        // Get refresh token if it doesn't exist.
        server.handleClient();
    #else
        refreshToken();
        knobPosition(volumeKnobPin);
    #endif
}