/**
 * Rectangle.cpp
 * Project UID 2e6ea4e086ea6a06753e819c30923369
 *
 * EECS 183
 * Project 4: CoolPics
 *
 * Rishi Baronia, Allen Shen
 * rbaronia, shenal
 *
 * <#Description#>
 */

#include "Rectangle.h"
#include "Line.h"
#include "Triangle.h"
#include "Graphics.h"
#include <algorithm>
using namespace std;

// TODO: implement three constructors, setStart, getStart, setEnd, getEnd,
//       setColor, setColorTopLeft, getColorTopLeft, setColorTopRight,
//       getColorTopRight, setColorBottomRight, getColorBottomRight,
//       setColorBottomLeft, getColorBottomLeft, read, write.


// default constructor
Rectangle::Rectangle() {
    
}

// non-default contructor
Rectangle::Rectangle(Point pt1, Point pt2, Color color) {
    start = pt1;
    end = pt2;
    colorTopLeft = color;
    colorTopRight = color;
    colorBottomLeft = color;
    colorBottomRight = color;
}

// non-default constructor
Rectangle::Rectangle(Point pt1, Point pt2, Color cTopLeft, Color cTopRight,
                     Color cBottomRight, Color cBottomLeft) {
    start = pt1;
    end = pt2;
    colorTopLeft = cTopLeft;
    colorTopRight = cTopRight;
    colorBottomRight = cBottomRight;
    colorBottomLeft = cBottomLeft;
}

// sets start point
void Rectangle::setStart(Point pt) {
    start = pt;
}

// returns the start point
Point Rectangle::getStart() {
    return start;
}

// sets end point
void Rectangle::setEnd(Point pt) {
    end = pt;
}

// returns end point
Point Rectangle::getEnd() {
    return end;
}

// sets the entire rectangle to a color
void Rectangle::setColor(Color color) {
    colorTopRight = color;
    colorTopLeft = color;
    colorBottomRight = color;
    colorBottomLeft = color;
}

// sets top left color
void Rectangle::setColorTopLeft(Color color) {
    colorTopLeft = color;
}

// returns top left color
Color Rectangle::getColorTopLeft() {
    return colorTopLeft;
}

// sets top right color
void Rectangle::setColorTopRight(Color color) {
    colorTopRight = color;
}

// returns top right color
Color Rectangle::getColorTopRight() {
    return colorTopRight;
}

// sets bottom left color
void Rectangle::setColorBottomLeft(Color color) {
    colorBottomLeft = color;
}

// returns bottom left color
Color Rectangle::getColorBottomLeft() {
    return colorBottomLeft;
}

// sets bottom right color
void Rectangle::setColorBottomRight(Color color) {
    colorBottomRight = color;
}

// returns bottom right color
Color Rectangle::getColorBottomRight() {
    return colorBottomRight;
}

// Reads in rectangle from a .txt file
void Rectangle::read(istream& ins) {
    if (ins.good()) {
        ins >> start >> end >> colorTopLeft >> colorTopRight >> colorBottomRight
            >> colorBottomLeft;
    }
    if (ins.fail()) {
        ins.clear();
        setColor(colorTopLeft);
    
    }
    
}
    
// Outputs a rectangle in the following form:
// Start point, end point, top left color, top right color
// bottom right color, bottom left color
void Rectangle::write(ostream &outs) {
    if (outs.good()) {
        outs << start << end << colorTopLeft << colorTopRight
        << colorBottomRight << colorBottomLeft;
    }
}

// Your code goes above this line.
// Don't change the implementations below!

istream& operator >> (istream& ins, Rectangle& rectangle)
{
    rectangle.read(ins);
    return ins;
}

ostream& operator << (ostream& outs, Rectangle rectangle)
{
    rectangle.write(outs);
    return outs;
}

void Rectangle::draw(Graphics & drawer)
{
    // four points of rectangles
    Point topLeft = start;
    Point topRight(end.getX(), start.getY());
    Point bottomRight = end;
    Point bottomLeft(start.getX(), end.getY());

    // center point and color by averaging
    Point center((start.getX() + end.getX()) / 2,
                 (start.getY() + end.getY()) / 2);
    Color colorCenter((colorTopLeft.getRed() + colorTopRight.getRed() +
                       colorBottomRight.getRed() +
                       colorBottomLeft.getRed()) / 4,
                      (colorTopLeft.getGreen() + colorTopRight.getGreen() +
                       colorBottomRight.getGreen() +
                       colorBottomLeft.getGreen()) / 4,
                      (colorTopLeft.getBlue() + colorTopRight.getBlue() +
                       colorBottomRight.getBlue() +
                       colorBottomLeft.getBlue()) / 4);

    // four triangles to represent rectangle
    Triangle top(topLeft, colorTopLeft, topRight, colorTopRight,
                 center, colorCenter);
    Triangle bottom(bottomLeft, colorBottomLeft, bottomRight, colorBottomRight,
                    center, colorCenter);
    Triangle left(topLeft, colorTopLeft, bottomLeft, colorBottomLeft,
                  center, colorCenter);
    Triangle right(topRight, colorTopRight, bottomRight, colorBottomRight,
                   center, colorCenter);
    top.draw(drawer);
    bottom.draw(drawer);
    left.draw(drawer);
    right.draw(drawer);
}
