#include <Arduino.h>
#include <Panel.h>

#define PIN_BT 16 // button interrupt pin

#define PIN_CLA 12 // Latch pin (CLA on IKEA panel)
#define PIN_CLK 14 // Clock pin (CLKDI on IKEA panel)
#define PIN_IN 27  // Data pin (IN on IKEA panel)
#define PIN_EN 26  // Enable pin (EN on IKEA panel)

#define TIMING 1 // Amount of microseconds between pulses when sending data

Panel panel(PIN_CLA, PIN_CLK, PIN_IN, PIN_EN, TIMING);

void showNumber(int number, int x_offset, int y_offset)
{
    for (int i= 0; i <7; i++)
        {
            for (int j = 0; j < 7; j++)
            {
                panel.setPixel(i + x_offset, j + y_offset, 0);
            }
        }
        panel.show();
        
    switch (number)
    {
        case 0:
            panel.setPixel(2 + x_offset,0 + y_offset,1);
            panel.setPixel(3 + x_offset,0 + y_offset,1);
            panel.setPixel(4 + x_offset,0 + y_offset,1);
            panel.setPixel(5 + x_offset,0 + y_offset,1);

            panel.setPixel(1 + x_offset,1 + y_offset,1);
            panel.setPixel(2 + x_offset,1 + y_offset,1);
            panel.setPixel(3 + x_offset,1 + y_offset,1);
            panel.setPixel(4 + x_offset,1 + y_offset,1);
            panel.setPixel(5 + x_offset,1 + y_offset,1);
            panel.setPixel(6 + x_offset,1 + y_offset,1);

            panel.setPixel(1 + x_offset,2 + y_offset,1);
            panel.setPixel(2 + x_offset,2 + y_offset,1);
            panel.setPixel(5 + x_offset,2 + y_offset,1);
            panel.setPixel(6 + x_offset,2 + y_offset,1);

            panel.setPixel(1 + x_offset,3 + y_offset,1);
            panel.setPixel(2 + x_offset,3 + y_offset,1);
            panel.setPixel(5 + x_offset,3 + y_offset,1);
            panel.setPixel(6 + x_offset,3 + y_offset,1);

            panel.setPixel(1 + x_offset,4 + y_offset,1);
            panel.setPixel(2 + x_offset,4 + y_offset,1);
            panel.setPixel(5 + x_offset,4 + y_offset,1);
            panel.setPixel(6 + x_offset,4 + y_offset,1);

            panel.setPixel(1 + x_offset,5 + y_offset,1);
            panel.setPixel(2 + x_offset,5 + y_offset,1);
            panel.setPixel(3 + x_offset,5 + y_offset,1);
            panel.setPixel(4 + x_offset,5 + y_offset,1);
            panel.setPixel(5 + x_offset,5 + y_offset,1);
            panel.setPixel(6 + x_offset,5 + y_offset,1);

            panel.setPixel(2 + x_offset,6 + y_offset,1);
            panel.setPixel(3 + x_offset,6 + y_offset,1);
            panel.setPixel(4 + x_offset,6 + y_offset,1);
            panel.setPixel(5 + x_offset,6 + y_offset,1);

            break;

        case 1:
            panel.setPixel(3 + x_offset,0 + y_offset,1);
            panel.setPixel(4 + x_offset,0 + y_offset,1);

            panel.setPixel(3 + x_offset,1 + y_offset,1);
            panel.setPixel(4 + x_offset,1 + y_offset,1);

            panel.setPixel(3 + x_offset,2 + y_offset,1);
            panel.setPixel(4 + x_offset,2 + y_offset,1);

            panel.setPixel(3 + x_offset,3 + y_offset,1);
            panel.setPixel(4 + x_offset,3 + y_offset,1);

            panel.setPixel(3 + x_offset,4 + y_offset,1);
            panel.setPixel(4 + x_offset,4 + y_offset,1);

            panel.setPixel(2 + x_offset,5 + y_offset,1);
            panel.setPixel(3 + x_offset,5 + y_offset,1);
            panel.setPixel(4 + x_offset,5 + y_offset,1);

            panel.setPixel(3 + x_offset,6 + y_offset,1);
            panel.setPixel(4 + x_offset,6 + y_offset,1);

            break;

        case 2:
            panel.setPixel(1 + x_offset,0 + y_offset,1);
            panel.setPixel(2 + x_offset,0 + y_offset,1);
            panel.setPixel(3 + x_offset,0 + y_offset,1);
            panel.setPixel(4 + x_offset,0 + y_offset,1);
            panel.setPixel(5 + x_offset,0 + y_offset,1);
            panel.setPixel(6 + x_offset,0 + y_offset,1);

            panel.setPixel(1 + x_offset,1 + y_offset,1);
            panel.setPixel(2 + x_offset,1 + y_offset,1);
            panel.setPixel(3 + x_offset,1 + y_offset,1);
            panel.setPixel(4 + x_offset,1 + y_offset,1);
            panel.setPixel(5 + x_offset,1 + y_offset,1);
            panel.setPixel(6 + x_offset,1 + y_offset,1);

            panel.setPixel(2 + x_offset,2 + y_offset,1);
            panel.setPixel(3 + x_offset,2 + y_offset,1);

            panel.setPixel(3 + x_offset,3 + y_offset,1);
            panel.setPixel(4 + x_offset,3 + y_offset,1);
            panel.setPixel(5 + x_offset,3 + y_offset,1);

            panel.setPixel(5 + x_offset,4 + y_offset,1);
            panel.setPixel(6 + x_offset,4 + y_offset,1);
 
            panel.setPixel(1 + x_offset,5 + y_offset,1);
            panel.setPixel(2 + x_offset,5 + y_offset,1);
            panel.setPixel(3 + x_offset,5 + y_offset,1);
            panel.setPixel(4 + x_offset,5 + y_offset,1);
            panel.setPixel(5 + x_offset,5 + y_offset,1);
            panel.setPixel(6 + x_offset,5 + y_offset,1);

            panel.setPixel(2 + x_offset,6 + y_offset,1);
            panel.setPixel(3 + x_offset,6 + y_offset,1);
            panel.setPixel(4 + x_offset,6 + y_offset,1);
            panel.setPixel(5 + x_offset,6 + y_offset,1);

            break;

        case 3:
            panel.setPixel(2 + x_offset,0 + y_offset,1);
            panel.setPixel(3 + x_offset,0 + y_offset,1);
            panel.setPixel(4 + x_offset,0 + y_offset,1);
            panel.setPixel(5 + x_offset,0 + y_offset,1);

            panel.setPixel(1 + x_offset,1 + y_offset,1);
            panel.setPixel(2 + x_offset,1 + y_offset,1);
            panel.setPixel(3 + x_offset,1 + y_offset,1);
            panel.setPixel(4 + x_offset,1 + y_offset,1);
            panel.setPixel(5 + x_offset,1 + y_offset,1);
            panel.setPixel(6 + x_offset,1 + y_offset,1);

            panel.setPixel(5 + x_offset,2 + y_offset,1);
            panel.setPixel(6 + x_offset,2 + y_offset,1);

            panel.setPixel(1 + x_offset,3 + y_offset,1);
            panel.setPixel(2 + x_offset,3 + y_offset,1);
            panel.setPixel(3 + x_offset,3 + y_offset,1);
            panel.setPixel(4 + x_offset,3 + y_offset,1);
            panel.setPixel(5 + x_offset,3 + y_offset,1);
            panel.setPixel(6 + x_offset,3 + y_offset,1);

            panel.setPixel(5 + x_offset,4 + y_offset,1);
            panel.setPixel(6 + x_offset,4 + y_offset,1);

            panel.setPixel(1 + x_offset,5 + y_offset,1);
            panel.setPixel(2 + x_offset,5 + y_offset,1);
            panel.setPixel(3 + x_offset,5 + y_offset,1);
            panel.setPixel(4 + x_offset,5 + y_offset,1);
            panel.setPixel(5 + x_offset,5 + y_offset,1);
            panel.setPixel(6 + x_offset,5 + y_offset,1);

            panel.setPixel(2 + x_offset,6 + y_offset,1);
            panel.setPixel(3 + x_offset,6 + y_offset,1);
            panel.setPixel(4 + x_offset,6 + y_offset,1);
            panel.setPixel(5 + x_offset,6 + y_offset,1);


            break;


        case 4:
            panel.setPixel(5 + x_offset,0 + y_offset,1);
            panel.setPixel(6 + x_offset,0 + y_offset,1);

            panel.setPixel(5 + x_offset,1 + y_offset,1);
            panel.setPixel(6 + x_offset,1 + y_offset,1);

            panel.setPixel(5 + x_offset,2 + y_offset,1);
            panel.setPixel(6 + x_offset,2 + y_offset,1);

            panel.setPixel(1 + x_offset,3 + y_offset,1);
            panel.setPixel(2 + x_offset,3 + y_offset,1);
            panel.setPixel(3 + x_offset,3 + y_offset,1);
            panel.setPixel(4 + x_offset,3 + y_offset,1);
            panel.setPixel(5 + x_offset,3 + y_offset,1);
            panel.setPixel(6 + x_offset,3 + y_offset,1);

            panel.setPixel(1 + x_offset,4 + y_offset,1);
            panel.setPixel(2 + x_offset,4 + y_offset,1);
            panel.setPixel(5 + x_offset,4 + y_offset,1);
            panel.setPixel(6 + x_offset,4 + y_offset,1);

            panel.setPixel(1 + x_offset,5 + y_offset,1);
            panel.setPixel(2 + x_offset,5 + y_offset,1);
            panel.setPixel(5 + x_offset,5 + y_offset,1);
            panel.setPixel(6 + x_offset,5 + y_offset,1);

            panel.setPixel(1 + x_offset,6 + y_offset,1);
            panel.setPixel(2 + x_offset,6 + y_offset,1);
            panel.setPixel(5 + x_offset,6 + y_offset,1);
            panel.setPixel(6 + x_offset,6 + y_offset,1);


            break;

        case 5:
            panel.setPixel(2 + x_offset,0 + y_offset,1);
            panel.setPixel(3 + x_offset,0 + y_offset,1);
            panel.setPixel(4 + x_offset,0 + y_offset,1);
            panel.setPixel(5 + x_offset,0 + y_offset,1);

            panel.setPixel(1 + x_offset,1 + y_offset,1);
            panel.setPixel(2 + x_offset,1 + y_offset,1);
            panel.setPixel(3 + x_offset,1 + y_offset,1);
            panel.setPixel(4 + x_offset,1 + y_offset,1);
            panel.setPixel(5 + x_offset,1 + y_offset,1);
            panel.setPixel(6 + x_offset,1 + y_offset,1);

            panel.setPixel(5 + x_offset,2 + y_offset,1);
            panel.setPixel(6 + x_offset,2 + y_offset,1);

            panel.setPixel(1 + x_offset,3 + y_offset,1);
            panel.setPixel(2 + x_offset,3 + y_offset,1);
            panel.setPixel(3 + x_offset,3 + y_offset,1);
            panel.setPixel(4 + x_offset,3 + y_offset,1);
            panel.setPixel(5 + x_offset,3 + y_offset,1);
            panel.setPixel(6 + x_offset,3 + y_offset,1);

            panel.setPixel(1 + x_offset,4 + y_offset,1);
            panel.setPixel(2 + x_offset,4 + y_offset,1);

            panel.setPixel(1 + x_offset,5 + y_offset,1);
            panel.setPixel(2 + x_offset,5 + y_offset,1);
            panel.setPixel(3 + x_offset,5 + y_offset,1);
            panel.setPixel(4 + x_offset,5 + y_offset,1);
            panel.setPixel(5 + x_offset,5 + y_offset,1);
            panel.setPixel(6 + x_offset,5 + y_offset,1);

            panel.setPixel(1 + x_offset,6 + y_offset,1);
            panel.setPixel(2 + x_offset,6 + y_offset,1);
            panel.setPixel(3 + x_offset,6 + y_offset,1);
            panel.setPixel(4 + x_offset,6 + y_offset,1);
            panel.setPixel(5 + x_offset,6 + y_offset,1);
            panel.setPixel(6 + x_offset,6 + y_offset,1);


            break;


        case 6:
            panel.setPixel(2 + x_offset,0 + y_offset,1);
            panel.setPixel(3 + x_offset,0 + y_offset,1);
            panel.setPixel(4 + x_offset,0 + y_offset,1);
            panel.setPixel(5 + x_offset,0 + y_offset,1);

            panel.setPixel(1 + x_offset,1 + y_offset,1);
            panel.setPixel(2 + x_offset,1 + y_offset,1);
            panel.setPixel(3 + x_offset,1 + y_offset,1);
            panel.setPixel(4 + x_offset,1 + y_offset,1);
            panel.setPixel(5 + x_offset,1 + y_offset,1);
            panel.setPixel(6 + x_offset,1 + y_offset,1);

            panel.setPixel(1 + x_offset,2 + y_offset,1);
            panel.setPixel(2 + x_offset,2 + y_offset,1);
            panel.setPixel(5 + x_offset,2 + y_offset,1);
            panel.setPixel(6 + x_offset,2 + y_offset,1);

            panel.setPixel(1 + x_offset,3 + y_offset,1);
            panel.setPixel(2 + x_offset,3 + y_offset,1);
            panel.setPixel(3 + x_offset,3 + y_offset,1);
            panel.setPixel(4 + x_offset,3 + y_offset,1);
            panel.setPixel(5 + x_offset,3 + y_offset,1);

            panel.setPixel(1 + x_offset,4 + y_offset,1);
            panel.setPixel(2 + x_offset,4 + y_offset,1);

            panel.setPixel(1 + x_offset,5 + y_offset,1);
            panel.setPixel(2 + x_offset,5 + y_offset,1);
            panel.setPixel(3 + x_offset,5 + y_offset,1);
            panel.setPixel(4 + x_offset,5 + y_offset,1);
            panel.setPixel(5 + x_offset,5 + y_offset,1);
            panel.setPixel(6 + x_offset,5 + y_offset,1);

            panel.setPixel(2 + x_offset,6 + y_offset,1);
            panel.setPixel(3 + x_offset,6 + y_offset,1);
            panel.setPixel(4 + x_offset,6 + y_offset,1);
            panel.setPixel(5 + x_offset,6 + y_offset,1);

            break;

        case 7:
            panel.setPixel(3 + x_offset,0 + y_offset,1);
            panel.setPixel(4 + x_offset,0 + y_offset,1);

            panel.setPixel(3 + x_offset,1 + y_offset,1);
            panel.setPixel(4 + x_offset,1 + y_offset,1);

            panel.setPixel(3 + x_offset,2 + y_offset,1);
            panel.setPixel(4 + x_offset,2 + y_offset,1);

            panel.setPixel(3 + x_offset,3 + y_offset,1);
            panel.setPixel(4 + x_offset,3 + y_offset,1);
            panel.setPixel(5 + x_offset,3 + y_offset,1);

            panel.setPixel(5 + x_offset,4 + y_offset,1);
            panel.setPixel(6 + x_offset,4 + y_offset,1);

            panel.setPixel(1 + x_offset,5 + y_offset,1);
            panel.setPixel(2 + x_offset,5 + y_offset,1);
            panel.setPixel(3 + x_offset,5 + y_offset,1);
            panel.setPixel(4 + x_offset,5 + y_offset,1);
            panel.setPixel(5 + x_offset,5 + y_offset,1);
            panel.setPixel(6 + x_offset,5 + y_offset,1);

            panel.setPixel(1 + x_offset,6 + y_offset,1);
            panel.setPixel(2 + x_offset,6 + y_offset,1);
            panel.setPixel(3 + x_offset,6 + y_offset,1);
            panel.setPixel(4 + x_offset,6 + y_offset,1);
            panel.setPixel(5 + x_offset,6 + y_offset,1);
            panel.setPixel(6 + x_offset,6 + y_offset,1);

            break;

        case 8:
            panel.setPixel(2 + x_offset,0 + y_offset,1);
            panel.setPixel(3 + x_offset,0 + y_offset,1);
            panel.setPixel(4 + x_offset,0 + y_offset,1);
            panel.setPixel(5 + x_offset,0 + y_offset,1);

            panel.setPixel(1 + x_offset,1 + y_offset,1);
            panel.setPixel(2 + x_offset,1 + y_offset,1);
            panel.setPixel(3 + x_offset,1 + y_offset,1);
            panel.setPixel(4 + x_offset,1 + y_offset,1);
            panel.setPixel(5 + x_offset,1 + y_offset,1);
            panel.setPixel(6 + x_offset,1 + y_offset,1);

            panel.setPixel(1 + x_offset,2 + y_offset,1);
            panel.setPixel(2 + x_offset,2 + y_offset,1);
            panel.setPixel(5 + x_offset,2 + y_offset,1);
            panel.setPixel(6 + x_offset,2 + y_offset,1);

            panel.setPixel(3 + x_offset,3 + y_offset,1);
            panel.setPixel(4 + x_offset,3 + y_offset,1);

            panel.setPixel(1 + x_offset,4 + y_offset,1);
            panel.setPixel(2 + x_offset,4 + y_offset,1);
            panel.setPixel(5 + x_offset,4 + y_offset,1);
            panel.setPixel(6 + x_offset,4 + y_offset,1);

            panel.setPixel(1 + x_offset,5 + y_offset,1);
            panel.setPixel(2 + x_offset,5 + y_offset,1);
            panel.setPixel(3 + x_offset,5 + y_offset,1);
            panel.setPixel(4 + x_offset,5 + y_offset,1);
            panel.setPixel(5 + x_offset,5 + y_offset,1);
            panel.setPixel(6 + x_offset,5 + y_offset,1);

            panel.setPixel(2 + x_offset,6 + y_offset,1);
            panel.setPixel(3 + x_offset,6 + y_offset,1);
            panel.setPixel(4 + x_offset,6 + y_offset,1);
            panel.setPixel(5 + x_offset,6 + y_offset,1);

            break;

        case 9:
            panel.setPixel(2 + x_offset,0 + y_offset,1);
            panel.setPixel(3 + x_offset,0 + y_offset,1);
            panel.setPixel(4 + x_offset,0 + y_offset,1);
            panel.setPixel(5 + x_offset,0 + y_offset,1);

            panel.setPixel(1 + x_offset,1 + y_offset,1);
            panel.setPixel(2 + x_offset,1 + y_offset,1);
            panel.setPixel(3 + x_offset,1 + y_offset,1);
            panel.setPixel(4 + x_offset,1 + y_offset,1);
            panel.setPixel(5 + x_offset,1 + y_offset,1);
            panel.setPixel(6 + x_offset,1 + y_offset,1);

            panel.setPixel(5 + x_offset,2 + y_offset,1);
            panel.setPixel(6 + x_offset,2 + y_offset,1);

            panel.setPixel(1 + x_offset,3 + y_offset,1);
            panel.setPixel(2 + x_offset,3 + y_offset,1);
            panel.setPixel(3 + x_offset,3 + y_offset,1);
            panel.setPixel(4 + x_offset,3 + y_offset,1);
            panel.setPixel(5 + x_offset,3 + y_offset,1);
            panel.setPixel(6 + x_offset,3 + y_offset,1);

            panel.setPixel(1 + x_offset,4 + y_offset,1);
            panel.setPixel(2 + x_offset,4 + y_offset,1);
            panel.setPixel(5 + x_offset,4 + y_offset,1);
            panel.setPixel(6 + x_offset,4 + y_offset,1);

            panel.setPixel(1 + x_offset,5 + y_offset,1);
            panel.setPixel(2 + x_offset,5 + y_offset,1);
            panel.setPixel(3 + x_offset,5 + y_offset,1);
            panel.setPixel(4 + x_offset,5 + y_offset,1);
            panel.setPixel(5 + x_offset,5 + y_offset,1);
            panel.setPixel(6 + x_offset,5 + y_offset,1);

            panel.setPixel(2 + x_offset,6 + y_offset,1);
            panel.setPixel(3 + x_offset,6 + y_offset,1);
            panel.setPixel(4 + x_offset,6 + y_offset,1);
            panel.setPixel(5 + x_offset,6 + y_offset,1);

            break;

        default:
            break;
    }
    panel.show();
}

void setup()
{
  panel.begin();
  panel.clear();
  Serial.begin(9600);

  pinMode(PIN_BT, INPUT_PULLUP);
}
void loop()
{
    showNumber(0,0,0);
    showNumber(0,9,0);
    showNumber(0,0,9);
    showNumber(0,9,9);
    panel.show();
    delay(2000);
    panel.clear();

    showNumber(1,0,0);
    showNumber(1,9,0);
    showNumber(1,0,9);
    showNumber(1,9,9);
    panel.show();
    delay(2000);
    panel.clear();

    showNumber(2,0,0);
    showNumber(2,9,0);
    showNumber(2,0,9);
    showNumber(2,9,9);
    panel.show();
    delay(2000);
    panel.clear();

    showNumber(3,0,0);
    showNumber(3,9,0);
    showNumber(3,0,9);
    showNumber(3,9,9);
    panel.show();
    delay(2000);
    panel.clear();

    showNumber(4,0,0);
    showNumber(4,9,0);
    showNumber(4,0,9);
    showNumber(4,9,9);
    panel.show();
    delay(2000);
    panel.clear();

    showNumber(5,0,0);
    showNumber(5,9,0);
    showNumber(5,0,9);
    showNumber(5,9,9);
    panel.show();
    delay(2000);
    panel.clear();

    showNumber(6,0,0);
    showNumber(6,9,0);
    showNumber(6,0,9);
    showNumber(6,9,9);
    panel.show();
    delay(2000);
    panel.clear();

    showNumber(7,0,0);
    showNumber(7,9,0);
    showNumber(7,0,9);
    showNumber(7,9,9);
    panel.show();
    delay(2000);
    panel.clear();

    showNumber(8,0,0);
    showNumber(8,9,0);
    showNumber(8,0,9);
    showNumber(8,9,9);
    panel.show();
    delay(2000);
    panel.clear();

    showNumber(9,0,0);
    showNumber(9,9,0);
    showNumber(9,0,9);
    showNumber(9,9,9);
    panel.show();
    delay(2000);
    panel.clear();

    

}
