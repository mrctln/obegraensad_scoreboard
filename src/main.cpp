#include <Arduino.h>
#include <Panel.h>

#define PIN_CLA 12
#define PIN_CLK 14
#define PIN_IN 27
#define PIN_EN 26
#define TIMING 1

// Ein kompakter "Font": Jede Zahl (0-9) wird durch 7 Bytes repräsentiert.
// Jedes Byte steht für eine Zeile, die Bits darin für die 7 Pixel der Zeile.
const uint8_t font[10][7] = {
  {0x3C, 0x7E, 0x66, 0x66, 0x66, 0x7E, 0x3C}, // 0
  {0x18, 0x18, 0x18, 0x18, 0x18, 0x1C, 0x18}, // 1
  {0x7E, 0x7E, 0x0C, 0x38, 0x60, 0x7E, 0x3C}, // 2
  {0x3C, 0x7E, 0x60, 0x3C, 0x60, 0x7E, 0x3C}, // 3
  {0x66, 0x66, 0x66, 0x7E, 0x60, 0x60, 0x60}, // 4
  {0x7E, 0x7E, 0x60, 0x7C, 0x06, 0x7E, 0x7E}, // 5
  {0x3C, 0x7E, 0x66, 0x7C, 0x60, 0x7E, 0x3C}, // 6
  {0x18, 0x18, 0x18, 0x30, 0x60, 0x7E, 0x7E}, // 7
  {0x3C, 0x7E, 0x66, 0x3C, 0x66, 0x7E, 0x3C}, // 8
  {0x3C, 0x7E, 0x06, 0x3E, 0x66, 0x7E, 0x3C}  // 9
};

Panel panel(PIN_CLA, PIN_CLK, PIN_IN, PIN_EN, TIMING);

void drawDigit(int num, int x, int y) {
  if (num < 0 || num > 9) return;
  for (int row = 0; row < 7; row++) {
    for (int col = 0; col < 7; col++) {
      // Wir prüfen, ob das Bit an der Stelle 'col' im Byte für 'row' gesetzt ist
      bool pixelOn = (font[num][row] >> (6 - col)) & 0x01;
      panel.setPixel(col + x, row + y, pixelOn);
    }
  }
}

void updateDisplay(const String& data) {
  if (data.length() < 4) return;
  panel.clear();
  drawDigit(data[0] - '0', 0, 9); // Gast Zehner
  drawDigit(data[1] - '0', 9, 9); // Gast Einer
  drawDigit(data[2] - '0', 0, 0); // Heim Zehner
  drawDigit(data[3] - '0', 9, 0); // Heim Einer
  panel.show();
}

void setup() {
  panel.begin();
  Serial.begin(9600);
  updateDisplay("0000"); // Startzustand
}

void loop() {
  if (Serial.available()) {
    String input = Serial.readStringUntil('\n');
    input.trim();
    if (input.length() == 4) {
      updateDisplay(input);
    }
  }
}
