#include "Arduino.h"
#include "Panel.h"

Screenbuffer::Screenbuffer(int _columns, int _rows)
{
    rows = _rows;
    columns = _columns;
    _data = (char *)malloc((columns * rows) * sizeof(char));

    for (int i = 0; i < columns * rows; i++)
    {
        _data[i] = 0;
    }
}

char Screenbuffer::read(int x, int y)
{
    int wrappedx = _wrapIndex(x, columns);
    int wrappedy = _wrapIndex(y, rows);

    return *(_data + (columns * wrappedy + wrappedx));
}

void Screenbuffer::write(int x, int y, char value)
{
    int wrappedx = _wrapIndex(x, columns);
    int wrappedy = _wrapIndex(y, rows);

    _data[columns * wrappedy + wrappedx] = 1 & value;
}

void Screenbuffer::writeRaw(char value[], int length)
{
    for (char i = 0; i < length; i++)
    {
        _data[i] = value[i];
    }
}

void Screenbuffer::clear()
{
    for (int i = 0; i < columns * rows; i++)
    {
        _data[i] = 0;
    }
}

void Screenbuffer::dump()
{
    int i2 = 0;
    for (int i = 0; i < columns * rows; i++)
    {
        Serial.print((char)_data[i]);
        Serial.print(" ");
        i2++;
        if (i2 >= columns)
        {
            Serial.println("");
            i2 = 0;
        }
    }
    Serial.println("");
}

void Screenbuffer::randomize()
{
    for (int i = 0; i < columns * rows; i++)
    {
        _data[i] = random(0, 2);
    }
}

void Screenbuffer::destroy()
{
    free(_data);
}

int Screenbuffer::_wrapIndex(int a, int b)
{
    return ((a % b) + b) % b;
}