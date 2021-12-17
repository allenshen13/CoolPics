/**
 * Color.cpp
 * Project UID 2e6ea4e086ea6a06753e819c30923369
 *
 * EECS 183
 * Project 4: CoolPics
 *
 * Rishi Baronia. Allen Shen
 * rbaronia, shenal
 *
 * Cpp file for the color class, implements different functions of color.h
 */

#include "Color.h"

// Default constructor
Color::Color() {
    red = 0;
    green = 0;
    blue = 0;
}

// Non-default constructor
Color::Color(int redVal, int greenVal, int blueVal) {
    red = checkRange(redVal);
    green = checkRange(greenVal);
    blue = checkRange(blueVal);
}

// sets the red value for a color, checks if in range
void Color::setRed(int redVal) {
    red = checkRange(redVal);
}

// sets the green value for a color, checks if in range
void Color::setGreen(int greenVal) {
    green = checkRange(greenVal);
}

// sets the blue value for a color, checks if in range
void Color::setBlue(int blueVal) {
    blue = checkRange(blueVal);
}

// returns red value
int Color::getRed() {
    return red;
}

// returns green value
int Color::getGreen() {
    return green;
}

// returns blue value
int Color::getBlue() {
    return blue;
}

// reads in color from .txt file
void Color::read(istream &ins) {
    if (ins.good()) {
        ins >> red >> green >> blue;
    }
    red = checkRange(red);
    green = checkRange(green);
    blue = checkRange(blue);
}
// outputs color
void Color::write(ostream &outs) {
    if (outs.good()) {
        outs << red << " " << green << " " << blue;
    }
}

//ensures color is in valid range 
int Color::checkRange(int val) {
    
    if (val >= 0 && val <= 255) {
        return val;
    }
    else if (val > 255) {
        return 255;
    }
    else {
        return 0;
    }
}

// Your code goes above this line.
// Don't change the implementations below!

istream& operator >> (istream& ins, Color& color)
{
   color.read(ins);
   return ins;
}

ostream& operator << (ostream& outs, Color color)
{
   color.write(outs);
   return outs;
}
