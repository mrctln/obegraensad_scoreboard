#include <Arduino.h>
#include <Panel.h>
#include <WiFi.h>
#include <String.h>

const char* ssid = "ESP32-WOODIES"; // Replace with your desired SSID
const char* password = "Test1234"; // Replace with your desired password


#define PIN_BT 16 // button interrupt pin

#define PIN_CLA 12 // Latch pin (CLA on IKEA panel)
#define PIN_CLK 14 // Clock pin (CLKDI on IKEA panel)
#define PIN_IN 27  // Data pin (IN on IKEA panel)
#define PIN_EN 26  // Enable pin (EN on IKEA panel)

#define TIMING 1 // Amount of microseconds between pulses when sending data

int guest1 = 0;
int guest2 = 0;
int home1 = 0;
int home2 = 0;



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

void showScore(int guest1, int guest2, int home1, int home2)
{
    panel.clear();
    showNumber(guest1, 9, 0);
    showNumber(guest2, 9, 9);
    showNumber(home1, 0, 0);
    showNumber(home2, 0, 9);
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
  showScore(guest1, guest2, home1, home2);
}
void loop()
{


  if (Serial.available()) {
    // Read the incoming string
    String command = Serial.readStringUntil('\n');
    //char command = Serial.read();
    Serial.println(command);
    String num1 = command.substring(0, 2);
    String num2 = command.substring(2, 4);
    Serial.println(num1);
    int int_num1 = num1.toInt();
    Serial.println("num1 = " + int_num1);
    int int_num2 = num2.toInt();
    Serial.println("num2 = " + int_num2);

    if (int_num1 < 10){
        guest1 = 0;
        guest2 = int_num1;
    }
    else {
        guest1 = num1.charAt(0);
        guest2 = num1.charAt(1);

    }
    if (int_num2 < 10){
        home1 = 0;
        home2 = int_num1;
    }
    else {
        home1 = num2.charAt(0);
        home2 = num2.charAt(1);

    }
    Serial.println("------------\n");
    Serial.println("guest1: " + guest1);
    Serial.println("guest2: " + guest2);
    Serial.println("home1: " + home1);
    Serial.println("home2: " + home2);
    Serial.println("------------\n");

    showScore(guest1, guest2, home1, home2);
  }
}
