/*
    Panel.h - Library for driving an IKEA Obegraensad LED matrix.
*/

#ifndef Screenbuffer_h
#define Screenbuffer_h

#include "Arduino.h"

class Screenbuffer {
    public:
        Screenbuffer(int columns, int rows);
        int rows;
        int columns;
        char read(int x, int y);
        void write(int x, int y, char value);
        void writeRaw(char[], int length);
        void dump();
        void destroy();
        void clear();
        void randomize();
        char* _data;
    private:
        int _wrapIndex(int a , int b);
};
#endif