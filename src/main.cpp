#include <Arduino.h>
#include <Panel.h>

#define PIN_BT 16 // button interrupt pin

#define PIN_CLA 12 // Latch pin (CLA on IKEA panel)
#define PIN_CLK 14 // Clock pin (CLKDI on IKEA panel)
#define PIN_IN 27  // Data pin (IN on IKEA panel)
#define PIN_EN 26  // Enable pin (EN on IKEA panel)

#define TIMING 1 // Amount of microseconds between pulses when sending data

Panel panel(PIN_CLA, PIN_CLK, PIN_IN, PIN_EN, TIMING);


void setup()
{
  panel.begin();
  panel.clear();
  Serial.begin(9600);

  pinMode(PIN_BT, INPUT_PULLUP);
}
void loop()
{

  panel.setPixel(0, 16, 1);
  panel.setPixel(16, 0, 1);
  panel.show();
  sleep(10);
  panel.clear();
}
