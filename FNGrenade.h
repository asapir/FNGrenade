#pragma once
#include <NeoPixelBus.h>

// Pins
const uint8_t Pixel1Pin = 3;
const uint8_t Pixel2Pin = 4;  
int TiltPin = 5;

// Number of leds per strip
const uint16_t PixelCount = 3;
#define colorSaturation 128

// the following variables are long because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long time = 0;         // the last time the output pin was toggled
long debounce = 20;   // the debounce time, increase if the output flickers
long activeTime = 0;
long activeDuration = 1000;

int reading;           // the current reading from the input pin
int previous = LOW;    // the previous reading from the input pin
int colorIndex = 0;
int steadyState = HIGH;
int stablePrev = LOW;


RgbColor red(colorSaturation, 0, 0);
RgbColor yellow(colorSaturation, colorSaturation, 0);
RgbColor green(0, colorSaturation, 0);
RgbColor light_blue(0, colorSaturation, colorSaturation);
RgbColor blue(0, 0, colorSaturation);
RgbColor purple(colorSaturation, 0, colorSaturation);
RgbColor white(colorSaturation);
RgbColor black(0);

HslColor hslRed(red);
HslColor hslGreen(green);
HslColor hslBlue(blue);
HslColor hslWhite(white);
HslColor hslBlack(black);

const uint16_t NumColors = 7;

RgbColor colorAry[NumColors] = {red, yellow, green, light_blue, blue, purple, white};
