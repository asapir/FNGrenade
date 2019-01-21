#include "FNGrenade.h"



extern NeoPixelBus<NeoGrbFeature, Neo800KbpsMethod> strip1;
extern NeoPixelBus<NeoGrbFeature, Neo800KbpsMethod> strip2;

// Fill the dots one after the other with a color
void colorWipe(RgbColor c, uint8_t wait) {
  for(uint16_t i=0; i<PixelCount; i++) {
    strip1.SetPixelColor(i, c);
    strip2.SetPixelColor(i, c);
  }
  strip1.Show();
  strip2.Show();
  delay(wait);
}

void activate(RgbColor c) {
  for(uint16_t i=0; i<PixelCount; i++) {
    strip1.SetPixelColor(i, 0);
    strip2.SetPixelColor(i, 0);
  }
  strip1.Show();
  strip2.Show();
  for(uint16_t i=0; i<PixelCount; i++) {
    strip1.SetPixelColor(i, c);
    strip2.SetPixelColor(i, c);
    strip1.Show();
    strip2.Show();
    delay(1000);
  }
  for(uint16_t i=0; i<3;i++) {
    colorWipe(black,500);
    colorWipe(c,500);
  }
}
