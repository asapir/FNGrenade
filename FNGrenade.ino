#include "FNGrenade.h"
#include "leds.h"


NeoPixelBus<NeoGrbFeature, Neo800KbpsMethod> strip1(PixelCount, Pixel1Pin);
NeoPixelBus<NeoGrbFeature, Neo800KbpsMethod> strip2(PixelCount, Pixel2Pin);

#define DEBUG 1

void setup()
{
  #ifdef DEBUG
  Serial.begin(9600);
  #endif
  pinMode(TiltPin, INPUT_PULLUP);
  strip1.Begin();
  strip2.Begin();
  strip1.Show();
  strip2.Show();
  steadyState = digitalRead(TiltPin);
}
 
void loop()
{
  int switchstate;
 
  reading = digitalRead(TiltPin);
 
  // If the switch changed, due to bounce or pressing...
  if (reading != previous) {
    // reset the debouncing timer
    time = millis();
  } 
 
  if ((millis() - time) > debounce) {
      // whatever the switch is at, its been there for a long time
      // so lets settle on it!
      switchstate = reading;
      #ifdef DEBUG
      Serial.print("steadyState=");
      Serial.print(steadyState);
      Serial.print(" switchstate=");
      Serial.print(switchstate);
      Serial.print(" stablePrev=");
      Serial.print(stablePrev);
      Serial.print(" previous=");
      Serial.println(previous);
      #endif

     
      colorWipe(colorAry[colorIndex], 50);
      if (switchstate != steadyState && switchstate != stablePrev) {
          // change color    
          colorIndex = (colorIndex+1)%NumColors;
          activeTime = millis();
      } 
      if (switchstate == steadyState) {
          activeTime = millis();
      }
      
      stablePrev = switchstate;
  }

  if ((millis() - activeTime) > activeDuration) {
    #ifdef DEBUG
    Serial.println("Activate !!!!"); 
    #endif
    activate(colorAry[colorIndex]);
    activeTime = millis();
  }
 
  // Save the last reading so we keep a running tally
  previous = reading;
}
