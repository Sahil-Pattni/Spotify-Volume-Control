//
// Created by Sahil Pattni on 2024-03-11.
//

#ifndef SPOTIFYVOLUME_CONTROLKNOB_H
#define SPOTIFYVOLUME_CONTROLKNOB_H

#include <Arduino.h>

const float maxPosition = 4095.0; // 10k potentiometer

// Read a potentiometer
int knobPosition(int pin, int interval);
int knobPosition(int pin);

#endif //SPOTIFYVOLUME_CONTROLKNOB_H
