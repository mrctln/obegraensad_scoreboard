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
