#include <Arduino.h>
#include <Panel.h>
#include <WiFi.h>

const char* ssid = "ESP32-WOODIES"; // Replace with your desired SSID
const char* password = "Test1234"; // Replace with your desired password


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

  // Set WiFi to station mode
  WiFi.mode(WIFI_STA);

   // Set WiFi to AP mode and configure SSID and password
  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid, password);

  Serial.print("AP IP address: ");
  Serial.println(WiFi.softAPIP());
}
void loop()
{
  if (Serial.available()) {
    // Read the incoming character
    char command = Serial.read();
    Serial.println(command);

    // Switch based on the received command
    switch (command) {
      case '1': 
        showNumber(1,0,0);
        break;

      case '2':
        showNumber(2,0,0);
        break;

      case '3':
        showNumber(3,0,0);
        break;

      default: // Invalid command
        Serial.println("Invalid command");
    }
  }
}
