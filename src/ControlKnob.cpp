
//
// Created by Sahil Pattni on 2024-03-11.
//

#include "../include/ControlKnob.h"

/**
 * Returns the position of the knob
 * bound by the interval [0, @param interval]
 * @param pin The GPIO pin connected to the module.
 * @param range The range to scale by.
 * @return
 */
int knobPosition(int pin, int interval) {
    int value = analogRead(pin);
    // return max if close to end (determined by manual testing)
    if (value < 25) return interval;

    // Invert bc left side is inactive
    float p = maxPosition - value;

    // Adjust to range and return
    return (p / maxPosition) * interval;
}

// Default wrapper to get percentage.
int knobPosition(int pin) {
    return knobPosition(pin, 100);
}