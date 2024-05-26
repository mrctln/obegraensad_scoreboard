#include <Arduino.h>
#include <Panel.h>
#include <Wifi.h>
#include <NTPClient.h>
#include <WiFiUdp.h>

#define PIN_BT 16 // button interrupt pin

#define PIN_CLA 12 // Latch pin (CLA on IKEA panel)
#define PIN_CLK 14 // Clock pin (CLKDI on IKEA panel)
#define PIN_IN 27  // Data pin (IN on IKEA panel)
#define PIN_EN 26  // Enable pin (EN on IKEA panel)

#define TIMING 1 // Amount of microseconds between pulses when sending data

Panel panel(PIN_CLA, PIN_CLK, PIN_IN, PIN_EN, TIMING);

Screenbuffer timebuffer(16, 5);
Screenbuffer animbuffer(16, 10);

unsigned long previousClock = 0;
unsigned long previousAnim = 0;
unsigned long previousInterrupt = 0;

unsigned char selectedAnim = 0;
unsigned int animframe = 0;

const unsigned long bitMap[11]{
    0b11101010101010101110,
    0b01001100010001001110,
    0b11100010111010001110,
    0b11100010111000101110,
    0b10101010111000100010,
    0b11101000111000101110,
    0b11101000111010101110,
    0b11100010001000100010,
    0b11101010111010101110,
    0b11101010111000101110,
    0b10101010101010101010,
};

void renderdigit(Screenbuffer buffer, int x, int y, int digit)
{
  long number = bitMap[digit];
  char column = 3;
  char row = 0;
  for (int i = 0; i < 20; i++)
  {
    buffer.write(x + column, y + row, (number >> i) & 1);
    if (column < 1)
    {
      column = 3;
      row++;
    }
    else
    {
      column--;
    }
  }
}

void renderTime()
{
  int hours = 12;
  int minutes = 41;

  if (hours < 10)
  {
    renderdigit(timebuffer, 0, 0, 0);
    renderdigit(timebuffer, 4, 0, hours);
  }
  else
  {
    int bignum = hours;
    while (bignum >= 10)
      bignum /= 10;
    renderdigit(timebuffer, 0, 0, bignum);
    renderdigit(timebuffer, 4, 0, hours % 10);
  }

  if (minutes < 10)
  {
    renderdigit(timebuffer, 8, 0, 0);
    renderdigit(timebuffer, 12, 0, minutes);
  }
  else
  {
    int bignum = minutes;
    while (bignum >= 10)
      bignum /= 10;
    renderdigit(timebuffer, 8, 0, bignum);
    renderdigit(timebuffer, 12, 0, minutes % 10);
  }
}

const int friendCoords[8][2] =
    {
        {0, 1},
        {1, 1},
        {1, 0},
        {1, -1},
        {0, -1},
        {-1, -1},
        {-1, 0},
        {-1, 1}};

int getFriends(int x, int y)
{
  int friends = 0;
  for (int i = 0; i < 8; i++)
  {
    friends += animbuffer.read(x + friendCoords[i][1], y + friendCoords[i][0]);
  }

  return friends;
}

void evolveBuffer()
{
  Screenbuffer newBuffer(animbuffer.columns, animbuffer.rows);
  newBuffer.clear();

  for (int y = 0; y < newBuffer.rows; y++)
  {
    for (int x = 0; x < newBuffer.columns; x++)
    {
      int friends = getFriends(x, y);

      switch (friends)
      {
      case 2:
        newBuffer.write(x, y, animbuffer.read(x, y));
        break;
      case 3:
        newBuffer.write(x, y, 1);
        break;
      default:
        newBuffer.write(x, y, 0);
        break;
      }
    }
  }

  animbuffer.destroy();
  animbuffer._data = newBuffer._data;
}

void updateClock() {
  renderTime();

  switch (selectedAnim)
  {
  case 0:
    panel.setBuffer(0, 11, timebuffer);
    break;
  case 1:
    panel.setBuffer(0, 0, timebuffer);
    break;
  case 2:
    panel.setBuffer(0, 6, timebuffer);
    break;
  case 3:
    break;
  default:
    selectedAnim = 0;
    panel.setBuffer(0, 11, timebuffer);
    break;
  }
}

void updateAnim() {
  switch (selectedAnim)
  {
  case 0:
    panel.setBuffer(0, 0, animbuffer);
    break;
  case 1:
    panel.setBuffer(0, 6, animbuffer);
    break;
  case 2:
    break;
  case 3:
    panel.setBuffer(0, 3, animbuffer);
    break;
  default:
    selectedAnim = 0;
    panel.setBuffer(0, 0, animbuffer);
    break;
  }
}

void cycleAnimation()
{
  unsigned long currentMillis = millis();
  if (currentMillis - previousInterrupt >= 1000) {
    previousInterrupt = currentMillis;
    selectedAnim++;
    panel.clear();
    panel.show();
    updateClock();
  }
}

void setup()
{
  panel.begin();
  panel.clear();
  Serial.begin(9600);

  pinMode(PIN_BT, INPUT_PULLUP);
  attachInterrupt(PIN_BT, cycleAnimation, FALLING);
}
void loop()
{
  unsigned long currentMillis = millis();

  if (currentMillis - previousAnim >= 750)
  {
    previousAnim = currentMillis;
    evolveBuffer();
    updateAnim();
    panel.show();

    animframe++;

    if (animframe > 60)
    {
      animbuffer.randomize();
      animframe = 0;
    }
  }

  if (currentMillis - previousClock >= 60000)
  {
    previousClock = currentMillis;
    renderTime();
    updateClock();
  }
}
