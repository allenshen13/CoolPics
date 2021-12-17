/**
 * Point.cpp
 * Project UID 2e6ea4e086ea6a06753e819c30923369
 *
 * EECS 183
 * Project 4: CoolPics
 *
 * Rishi Baronia, Allen Shen
 * rbaronia, shenal
 *
 * Cpp file for the point class, implements different functions of point.h
 */

#include "Point.h"


#include "utility.h"



// Default constructor
Point::Point() {
    x = 0;
    y = 0;
}
    
// Non-default constructor
Point::Point(int xVal, int yVal) {
    x = checkRange(xVal);
    y = checkRange(yVal);
}

// sets x value for point
void Point::setX(int xVal) {
    x = checkRange(xVal);

    return;
}

// returns x value of a point
int Point::getX() {
    return x;
}

// sets y value for point
void Point::setY(int yVal) {
    y = checkRange(yVal);
    
    return;
}
    
// returns y value for point
int Point::getY() {
    return y;
}

// reads point in from .txt file in the following form:
// x value, y value, while omitting (, ), and ,
void Point::read(istream& ins) {
    char a;
    
    if (ins.good()) {
        ins >> a >> x >> a >> y >> a;
    }
    x = checkRange(x);
    y = checkRange(y);
    return;
}

// outputs a point
void Point::write(ostream& outs) {
    
    if (outs.good()) {
        outs << "(" << getX() << ", " << getY() << ")";
    }

    return;
}

// checks if one of the values of point is in the range [0, dimension)
int Point::checkRange(int val) {
    if (val >= 0 && val < DIMENSION) {
        return val;
    }
    else if (val < 0) {
        return 0;
    }
    
        
    return DIMENSION - 1;
}


// Your code goes above this line.
// Don't change the implementations below!

istream& operator >> (istream& ins,  Point& pt)
{
    pt.read(ins);
    return ins;
}

ostream& operator<< (ostream& outs, Point pt)
{
    pt.write(outs);
    return outs;
}
