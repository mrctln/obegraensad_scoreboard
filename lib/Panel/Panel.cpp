#include "Arduino.h"
#include "Panel.h"

Panel::Panel(int pin_cla, int pin_clk, int pin_in, int pin_en, int timing)
{
    _pin_cla = pin_cla;
    _pin_clk = pin_clk;
    _pin_in = pin_in;
    _pin_en = pin_en;
    _timing = timing;
}

void Panel::begin()
{
    pinMode(_pin_cla, OUTPUT);
    pinMode(_pin_clk, OUTPUT);
    pinMode(_pin_in, OUTPUT);
    pinMode(_pin_en, OUTPUT);
}

void Panel::clear()
{
    for (int i = 0; i < 256; i++)
    {
        _panelBuffer[i] = 0;
    }
}

void Panel::show()
{
    digitalWrite(_pin_en, 1); // pull write pin high

    uint8_t w2 = 0; // Index of every 16 bit value we send.

    // Loop through every index of the buffer
    for (int i = 0; i < 256; i++)
    {
        // Write panel buffer to data pin, Ensuring only the last bit of the value is sent --> "00000001 AND value"
        digitalWrite(_pin_in, _panelBuffer[i]);

        // Create one clock pulse
        digitalWrite(_pin_clk, HIGH);
        delayMicroseconds(_timing);
        digitalWrite(_pin_clk, LOW);

        // increment counter tracking sent bits
        w2++;

        // Every 16 bits reset counter and pulse the latch pin. Saving the data to the shift register.
        // The shift register then passes its data on to the next connected chip on every following clock cycle.
        if (w2 > 15)
        {
            w2 = 0;
            digitalWrite(_pin_cla, HIGH);
            delayMicroseconds(_timing);
            digitalWrite(_pin_cla, LOW);
        }
    }
    digitalWrite(_pin_en, 0); // Pull write pin low;
}

void Panel::setPixel(int x, int y, int value)
{
    _panelBuffer[_addrTable[y][x]] = 1 & value;
}

void Panel::setBuffer(int x, int y, Screenbuffer buffer)
{
    for (int i = 0; i < buffer.rows; i++)
    {
        for (int j = 0; j < buffer.columns; j++)
        {
            _panelBuffer[_addrTable[_wrapIndex(i + y, 16)][_wrapIndex(j + x, 16)]] = buffer.read(j, i);
        }
    }
}

int Panel::_wrapIndex(int a, int b)
{
    return ((a % b) + b) % b;
}

void Panel::showNumber(int number, int x_offset, int y_offset)
{

    for (int i= 0; i <7; i++)
        {
            for (int j = 0; j < 7; j++)
            {
                setPixel(i, j, 0);
            }
        }
        show();
        
    switch (number)
    {
        case 0:
            setPixel(0 + y_offset,2 + x_offset,1);
            setPixel(0 + y_offset,3 + x_offset,1);
            setPixel(0 + y_offset,4 + x_offset,1);
            setPixel(0 + y_offset,5 + x_offset,1);
            
            setPixel(1 + y_offset,1 + x_offset,1);
            setPixel(1 + y_offset,2 + x_offset,1);
            setPixel(1 + y_offset,3 + x_offset,1);
            setPixel(1 + y_offset,4 + x_offset,1);
            setPixel(1 + y_offset,5 + x_offset,1);
            setPixel(1 + y_offset,6 + x_offset,1);

            setPixel(2 + y_offset,1 + x_offset,1);
            setPixel(2 + y_offset,2 + x_offset,1);
            setPixel(2 + y_offset,5 + x_offset,1);
            setPixel(2 + y_offset,6 + x_offset,1);

            setPixel(3 + y_offset,1 + x_offset,1);
            setPixel(3 + y_offset,2 + x_offset,1);
            setPixel(3 + y_offset,5 + x_offset,1);
            setPixel(3 + y_offset,6 + x_offset,1);

            setPixel(4 + y_offset,1 + x_offset,1);
            setPixel(4 + y_offset,2 + x_offset,1);
            setPixel(4 + y_offset,5 + x_offset,1);
            setPixel(4 + y_offset,6 + x_offset,1);

            setPixel(5 + y_offset,1 + x_offset,1);
            setPixel(5 + y_offset,2 + x_offset,1);
            setPixel(5 + y_offset,3 + x_offset,1);
            setPixel(5 + y_offset,4 + x_offset,1);
            setPixel(5 + y_offset,5 + x_offset,1);
            setPixel(5 + y_offset,6 + x_offset,1);

            setPixel(6 + y_offset,2 + x_offset,1);
            setPixel(6 + y_offset,3 + x_offset,1);
            setPixel(6 + y_offset,4 + x_offset,1);
            setPixel(6 + y_offset,5 + x_offset,1);
            break;


        case 1:
            setPixel(0 + y_offset,3 + x_offset,1);
            setPixel(0 + y_offset,4 + x_offset,1);
            
            
            setPixel(1 + y_offset,2 + x_offset,1);
            setPixel(1 + y_offset,3 + x_offset,1);
            setPixel(1 + y_offset,4 + x_offset,1);

            setPixel(2 + y_offset,3 + x_offset,1);
            setPixel(2 + y_offset,4 + x_offset,1);

            setPixel(3 + y_offset,3 + x_offset,1);
            setPixel(3 + y_offset,4 + x_offset,1);

            setPixel(4 + y_offset,3 + x_offset,1);
            setPixel(4 + y_offset,4 + x_offset,1);

            setPixel(5 + y_offset,3 + x_offset,1);
            setPixel(5 + y_offset,4 + x_offset,1);

            setPixel(6 + y_offset,3 + x_offset,1);
            setPixel(6 + y_offset,4 + x_offset,1);

            show();
            break;

        case 2:
            setPixel(0 + y_offset,2 + x_offset,1);
            setPixel(0 + y_offset,3 + x_offset,1);
            setPixel(0 + y_offset,4 + x_offset,1);
            setPixel(0 + y_offset,5 + x_offset,1);

            setPixel(1 + y_offset,1 + x_offset,1);
            setPixel(1 + y_offset,2 + x_offset,1);
            setPixel(1 + y_offset,3 + x_offset,1);
            setPixel(1 + y_offset,4 + x_offset,1);
            setPixel(1 + y_offset,5 + x_offset,1);
            setPixel(1 + y_offset,6 + x_offset,1);

            setPixel(2 + y_offset,5 + x_offset,1);
            setPixel(2 + y_offset,6 + x_offset,1);

            setPixel(3 + y_offset,3 + x_offset,1);
            setPixel(3 + y_offset,4 + x_offset,1);
            setPixel(3 + y_offset,5 + x_offset,1);

            setPixel(4 + y_offset,2 + x_offset,1);
            setPixel(4 + y_offset,3 + x_offset,1);

            setPixel(5 + y_offset,1 + x_offset,1);
            setPixel(5 + y_offset,2 + x_offset,1);
            setPixel(5 + y_offset,3 + x_offset,1);
            setPixel(5 + y_offset,4 + x_offset,1);
            setPixel(5 + y_offset,5 + x_offset,1);
            setPixel(5 + y_offset,6 + x_offset,1);

            setPixel(6 + y_offset,1 + x_offset,1);
            setPixel(6 + y_offset,2 + x_offset,1);
            setPixel(6 + y_offset,3 + x_offset,1);
            setPixel(6 + y_offset,4 + x_offset,1);
            setPixel(6 + y_offset,5 + x_offset,1);
            setPixel(6 + y_offset,6 + x_offset,1);

            show();
            break;

        case 3:
            setPixel(0 + y_offset,2 + x_offset,1);
            setPixel(0 + y_offset,3 + x_offset,1);
            setPixel(0 + y_offset,4 + x_offset,1);
            setPixel(0 + y_offset,5 + x_offset,1);

            setPixel(1 + y_offset,1 + x_offset,1);
            setPixel(1 + y_offset,2 + x_offset,1);
            setPixel(1 + y_offset,3 + x_offset,1);
            setPixel(1 + y_offset,4 + x_offset,1);
            setPixel(1 + y_offset,5 + x_offset,1);
            setPixel(1 + y_offset,6 + x_offset,1);

            setPixel(2 + y_offset,5 + x_offset,1);
            setPixel(2 + y_offset,6 + x_offset,1);

            setPixel(3 + y_offset,1 + x_offset,1);
            setPixel(3 + y_offset,2 + x_offset,1);
            setPixel(3 + y_offset,3 + x_offset,1);
            setPixel(3 + y_offset,4 + x_offset,1);
            setPixel(3 + y_offset,5 + x_offset,1);
            setPixel(3 + y_offset,6 + x_offset,1);

            setPixel(4 + y_offset,5 + x_offset,1);
            setPixel(4 + y_offset,6 + x_offset,1);

            setPixel(5 + y_offset,1 + x_offset,1);
            setPixel(5 + y_offset,2 + x_offset,1);
            setPixel(5 + y_offset,3 + x_offset,1);
            setPixel(5 + y_offset,4 + x_offset,1);
            setPixel(5 + y_offset,5 + x_offset,1);
            setPixel(5 + y_offset,6 + x_offset,1);

            setPixel(6 + y_offset,2 + x_offset,1);
            setPixel(6 + y_offset,3 + x_offset,1);
            setPixel(6 + y_offset,4 + x_offset,1);
            setPixel(6 + y_offset,5 + x_offset,1);

        case 4:
            setPixel(0 + y_offset,1 + x_offset,1);
            setPixel(0 + y_offset,2 + x_offset,1);
            setPixel(0 + y_offset,5 + x_offset,1);
            setPixel(0 + y_offset,6 + x_offset,1);

            setPixel(1 + y_offset,1 + x_offset,1);
            setPixel(1 + y_offset,2 + x_offset,1);
            setPixel(1 + y_offset,5 + x_offset,1);
            setPixel(1 + y_offset,6 + x_offset,1);

            setPixel(2 + y_offset,1 + x_offset,1);
            setPixel(2 + y_offset,2 + x_offset,1);
            setPixel(2 + y_offset,5 + x_offset,1);
            setPixel(2 + y_offset,6 + x_offset,1);

            setPixel(3 + y_offset,1 + x_offset,1);
            setPixel(3 + y_offset,2 + x_offset,1);
            setPixel(3 + y_offset,3 + x_offset,1);
            setPixel(3 + y_offset,4 + x_offset,1);
            setPixel(3 + y_offset,5 + x_offset,1);
            setPixel(3 + y_offset,6 + x_offset,1);

            setPixel(4 + y_offset,5 + x_offset,1);
            setPixel(4 + y_offset,6 + x_offset,1);

            setPixel(5 + y_offset,5 + x_offset,1);
            setPixel(5 + y_offset,6 + x_offset,1);

            setPixel(6 + y_offset,5 + x_offset,1);
            setPixel(6 + y_offset,6 + x_offset,1);

        case 5:
            setPixel(0 + y_offset,1 + x_offset,1);
            setPixel(0 + y_offset,2 + x_offset,1);
            setPixel(0 + y_offset,3 + x_offset,1);
            setPixel(0 + y_offset,4 + x_offset,1);
            setPixel(0 + y_offset,5 + x_offset,1);
            setPixel(0 + y_offset,6 + x_offset,1);

            setPixel(1 + y_offset,1 + x_offset,1);
            setPixel(1 + y_offset,2 + x_offset,1);
            setPixel(1 + y_offset,3 + x_offset,1);
            setPixel(1 + y_offset,4 + x_offset,1);
            setPixel(1 + y_offset,5 + x_offset,1);
            setPixel(1 + y_offset,6 + x_offset,1);

            setPixel(2 + y_offset,1 + x_offset,1);
            setPixel(2 + y_offset,2 + x_offset,1);

            setPixel(3 + y_offset,1 + x_offset,1);
            setPixel(3 + y_offset,2 + x_offset,1);
            setPixel(3 + y_offset,3 + x_offset,1);
            setPixel(3 + y_offset,4 + x_offset,1);
            setPixel(3 + y_offset,5 + x_offset,1);
            setPixel(3 + y_offset,6 + x_offset,1);

            setPixel(4 + y_offset,5 + x_offset,1);
            setPixel(4 + y_offset,6 + x_offset,1);

            setPixel(5 + y_offset,1 + x_offset,1);
            setPixel(5 + y_offset,2 + x_offset,1);
            setPixel(5 + y_offset,3 + x_offset,1);
            setPixel(5 + y_offset,4 + x_offset,1);
            setPixel(5 + y_offset,5 + x_offset,1);
            setPixel(5 + y_offset,6 + x_offset,1);

            setPixel(6 + y_offset,2 + x_offset,1);
            setPixel(6 + y_offset,3 + x_offset,1);
            setPixel(6 + y_offset,4 + x_offset,1);
            setPixel(6 + y_offset,5 + x_offset,1);

        case 6:
            setPixel(0 + y_offset,2 + x_offset,1);
            setPixel(0 + y_offset,3 + x_offset,1);
            setPixel(0 + y_offset,4 + x_offset,1);
            setPixel(0 + y_offset,5 + x_offset,1);

            setPixel(1 + y_offset,1 + x_offset,1);
            setPixel(1 + y_offset,2 + x_offset,1);
            setPixel(1 + y_offset,3 + x_offset,1);
            setPixel(1 + y_offset,4 + x_offset,1);
            setPixel(1 + y_offset,5 + x_offset,1);
            setPixel(1 + y_offset,6 + x_offset,1);

            setPixel(2 + y_offset,1 + x_offset,1);
            setPixel(2 + y_offset,2 + x_offset,1);

            setPixel(3 + y_offset,1 + x_offset,1);
            setPixel(3 + y_offset,2 + x_offset,1);
            setPixel(3 + y_offset,3 + x_offset,1);
            setPixel(3 + y_offset,4 + x_offset,1);
            setPixel(3 + y_offset,5 + x_offset,1);

            setPixel(4 + y_offset,1 + x_offset,1);
            setPixel(4 + y_offset,2 + x_offset,1);
            setPixel(4 + y_offset,5 + x_offset,1);
            setPixel(4 + y_offset,6 + x_offset,1);

            setPixel(5 + y_offset,1 + x_offset,1);
            setPixel(5 + y_offset,2 + x_offset,1);
            setPixel(5 + y_offset,3 + x_offset,1);
            setPixel(5 + y_offset,4 + x_offset,1);
            setPixel(5 + y_offset,5 + x_offset,1);
            setPixel(5 + y_offset,6 + x_offset,1);

            setPixel(6 + y_offset,2 + x_offset,1);
            setPixel(6 + y_offset,3 + x_offset,1);
            setPixel(6 + y_offset,4 + x_offset,1);
            setPixel(6 + y_offset,5 + x_offset,1);

        case 7:

            setPixel(0 + y_offset,1 + x_offset,1);
            setPixel(0 + y_offset,2 + x_offset,1);
            setPixel(0 + y_offset,3 + x_offset,1);
            setPixel(0 + y_offset,4 + x_offset,1);
            setPixel(0 + y_offset,5 + x_offset,1);
            setPixel(0 + y_offset,6 + x_offset,1);

            setPixel(1 + y_offset,1 + x_offset,1);
            setPixel(1 + y_offset,2 + x_offset,1);
            setPixel(1 + y_offset,3 + x_offset,1);
            setPixel(1 + y_offset,4 + x_offset,1);
            setPixel(1 + y_offset,5 + x_offset,1);
            setPixel(1 + y_offset,6 + x_offset,1);

            setPixel(2 + y_offset,5 + x_offset,1);
            setPixel(2 + y_offset,6 + x_offset,1);

            setPixel(3 + y_offset,3 + x_offset,1);
            setPixel(3 + y_offset,4 + x_offset,1);
            setPixel(3 + y_offset,5 + x_offset,1);

        case 8:
            setPixel(0 + y_offset,2 + x_offset,1);
            setPixel(0 + y_offset,3 + x_offset,1);
            setPixel(0 + y_offset,4 + x_offset,1);
            setPixel(0 + y_offset,5 + x_offset,1);

            setPixel(1 + y_offset,1 + x_offset,1);
            setPixel(1 + y_offset,2 + x_offset,1);
            setPixel(1 + y_offset,3 + x_offset,1);
            setPixel(1 + y_offset,4 + x_offset,1);
            setPixel(1 + y_offset,5 + x_offset,1);
            setPixel(1 + y_offset,6 + x_offset,1);

            setPixel(2 + y_offset,1 + x_offset,1);
            setPixel(2 + y_offset,2 + x_offset,1);
            setPixel(2 + y_offset,5 + x_offset,1);
            setPixel(2 + y_offset,6 + x_offset,1);

            setPixel(3 + y_offset,3 + x_offset,1);
            setPixel(3 + y_offset,4 + x_offset,1);

            setPixel(4 + y_offset,1 + x_offset,1);
            setPixel(4 + y_offset,2 + x_offset,1);
            setPixel(4 + y_offset,5 + x_offset,1);
            setPixel(4 + y_offset,6 + x_offset,1);

            setPixel(5 + y_offset,1 + x_offset,1);
            setPixel(5 + y_offset,2 + x_offset,1);
            setPixel(5 + y_offset,3 + x_offset,1);
            setPixel(5 + y_offset,4 + x_offset,1);
            setPixel(5 + y_offset,5 + x_offset,1);
            setPixel(5 + y_offset,6 + x_offset,1);

            setPixel(6 + y_offset,2 + x_offset,1);
            setPixel(6 + y_offset,3 + x_offset,1);
            setPixel(6 + y_offset,4 + x_offset,1);
            setPixel(6 + y_offset,5 + x_offset,1);

        case 9:
            setPixel(0 + y_offset,2 + x_offset,1);
            setPixel(0 + y_offset,3 + x_offset,1);
            setPixel(0 + y_offset,4 + x_offset,1);
            setPixel(0 + y_offset,5 + x_offset,1);

            setPixel(1 + y_offset,1 + x_offset,1);
            setPixel(1 + y_offset,2 + x_offset,1);
            setPixel(1 + y_offset,3 + x_offset,1);
            setPixel(1 + y_offset,4 + x_offset,1);
            setPixel(1 + y_offset,5 + x_offset,1);
            setPixel(1 + y_offset,6 + x_offset,1);

            setPixel(2 + y_offset,1 + x_offset,1);
            setPixel(2 + y_offset,2 + x_offset,1);
            setPixel(2 + y_offset,5 + x_offset,1);
            setPixel(2 + y_offset,6 + x_offset,1);

            setPixel(3 + y_offset,1 + x_offset,1);
            setPixel(3 + y_offset,2 + x_offset,1);
            setPixel(3 + y_offset,3 + x_offset,1);
            setPixel(3 + y_offset,4 + x_offset,1);
            setPixel(3 + y_offset,5 + x_offset,1);
            setPixel(3 + y_offset,6 + x_offset,1);

            setPixel(4 + y_offset,1 + x_offset,1);
            setPixel(4 + y_offset,2 + x_offset,1);

            setPixel(5 + y_offset,1 + x_offset,1);
            setPixel(5 + y_offset,2 + x_offset,1);
            setPixel(5 + y_offset,3 + x_offset,1);
            setPixel(5 + y_offset,4 + x_offset,1);
            setPixel(5 + y_offset,5 + x_offset,1);
            setPixel(5 + y_offset,6 + x_offset,1);

            setPixel(6 + y_offset,2 + x_offset,1);
            setPixel(6 + y_offset,3 + x_offset,1);
            setPixel(6 + y_offset,4 + x_offset,1);
            setPixel(6 + y_offset,5 + x_offset,1);


        default:
            break;
    }
    show();
}