# OBEGRÄNSAD Smart Clock
Walking through my nearby IKEA I stumbled across the OBEGRÄNSAD LED panel.
And I instantly had to Google if someone had managed to solder a microcontroller to it.
After finding [this](https://github.com/ph1p/ikea-led-obegraensad) repo by PH1P I just **had** to take one home and try to get it working for myself. 

The result of this endeavour is a graphics library that enables you to address individual pixels using their respective x/y coordinates. And the use of buffers that in turn can be rendered onto the screen. This allows you to split the screen into multiple areas, and have each area update independently.

![Clock-demo](media/clock-demo.gif)

## Getting started
PH1P has a great guide on modifying the display for this project [Here](https://github.com/ph1p/ikea-led-obegraensad#how-to)

### Pin-out

| Pin | Panel Marking | Notes |
|-----|---------------|-------|
| 23  | Side button   | One pin to ground, the other to an Interruptable pin on the microcontroller. |
| 27  | EN | Digital output |
| 26  | IN | Digital output |
| 25  | CLKDI | Digital output |
| 33  | CLA | Digital output |
| VCC | VCC | +5V |
| GND | GND | - |

You can modify the pins as you see fit. As long as the pin used for the side-button is able to receive interrupts. the definitions of each pin can be found at the top of the main file.

### Requirements
- [Visual studio Code](https://code.visualstudio.com/)
- [PlatformIO](https://platformio.org/platformio-ide)


## Features
The clock features four lay-outs that can be cycled by pressing the side button.

### Clock
The clock area is rendered at the top of the display using a custom font. The time is retrieved from a UTP server reached using the onboard WiFi of the ESP32.

### The Game of life
The showcase of the game of life on ph1p's repo inspired me to implement it as well. The calculations are done in a seperate buffer allowing for flexible placement of the grid. When reading/writing out of bounds, the coordinates are wrapped. This also allows for an "infinite" grid. 

## Future changes
- Optimize for size. The current library uses an array of chars to store the state of each pixel. As each pixel only has two states, this can theoretically be represented as a single bit. This would require packing each row of pixels into a single 16 bit integer. And shifting it out when sending the data to the screen registers.