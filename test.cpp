/**
 * test.cpp
 * Project UID 2e6ea4e086ea6a06753e819c30923369
 *
 * EECS 183
 * Project 4: CoolPics
 *
 * Allen Shen and Rishi Baronia
 * shenal & rbaronia
 *
 * Contains functions for testing classes in the project. 
 */

#include "Graphics.h"
#include "Circle.h"
#include "Color.h"
#include "Line.h"
#include "Point.h"
#include "Rectangle.h"
#include "Shape.h"
#include "Triangle.h"

#include <iostream>
#include <fstream>

using namespace std;


void test_Circle();
void test_Color();
void test_Line();
void test_Point();
void test_Rectangle();
void test_Triangle();

void startTests() {
    test_Point();
    test_Color();
    test_Rectangle();
    test_Line();
    test_Circle();
    test_Triangle();
    
    
    // call other test functions here
    
    return;
}

void test_Point() {
    // test of default constructor
    Point p1;
    cout << "Expected: (0,0), actual: " << p1 << endl;
    
    // test of the non-default constructor
    Point p2(3, 9);
    cout << "Expected: (3,9), actual: " << p2 << endl;

    // test of member function: setX()
    p1.setX(5);
    // test of member function: setY()
    p1.setY(3);

    // test of member functions getX() and getY()
    cout << "Expected: (5,3), actual: ";
    cout << "(" << p1.getX()
         << ", " << p1.getY()
         << ")" << endl;
    
    return;
}

void test_Color() {
    Color c1;
    cout << "Expected: (0, 0, 0), actual: " << c1 << endl;
    
    Color c2(10, 45, 200);
    cout << "Expected: (10, 45, 200), actual: " << c2 << endl;
    
    c1.setBlue(10);
    c1.setBlue(-256);
    cout << c1.getBlue() << endl;
    c1.setBlue(300);
    cout << c1.getBlue() << endl;
    c1.setBlue(-10);
    cout << c1.getBlue() << endl;
    c1.setBlue(125);
    cout << c1.getBlue() << endl;
    c1.setBlue(255);
    cout << c1.getBlue() << endl;
    c1.setRed(5);
    c1.setGreen(45);
    cout << "Expected: 10, actual: " << c1.getBlue() << endl;
    cout << "Expected: 45, actual: " << c1.getGreen() << endl;
    
    Color c3(266, -5, 30);
    cout << c3;
    
}

void test_Rectangle() {
    
    Rectangle r1;
    cout << r1 << endl;
    Point p1(1,1);
    Point p2(0,0);
    Color c1(0,0,0);
    Rectangle r2(p1, p2, c1);
    cout << r2 << endl;
    Color c2(255, 255, 255);
    Color c3(100, 100, 100);
    Color c4(23, 14, 45);
    Rectangle r3(p1, p2, c1, c2, c3, c4);
    cout << r3 << endl;
    cout << r2.getEnd() << endl;
    r2.setColor(c2);
    r2.setStart(p2);
    r2.setColorTopLeft(c2);
    r2.setColorTopRight(c2);
    r2.setColorBottomLeft(c2);
    r2.setColorBottomRight(c2);
    r2.setStart(p2);
    cout << r2.getColorTopLeft();
    cout << r2.getColorTopRight();
    cout << r2.getColorBottomLeft();
    cout << r2.getColorBottomRight();
    
    cout << r2.getStart() << endl;
    Point p3(3, 4);
    r2.setStart(p3);
    cout << r2.getStart() << endl;
    
    
}

void test_Line() {
    
    Line l1;
    cout << "Expected: (0,0) (0,0) 0 0 0 actual: " << l1 << endl;
    Point p1(2,3);
    Point p2(3,9);
    Point p3(65, 43);
    Color c1(20, 30, 255);
    Line l2(p1, p2, c1);
    cout << "Expected (2,3) (3,9) 20 30 255 actual: " << l2 << endl;
    cout << "Expected: " << p1 << " actual: " << l2.getStart() << endl;
    l2.setEnd(p1);
    cout << l2.getEnd();
    cout << "Expected: (2,3) (2,3) 20 30 255 actual: " << l2 << endl;
    l2.setEnd(p3);
                                                                                                            
}

void test_Circle() {
    Circle c1;
    cout << "Expected: " << c1 << endl;
    Point p1(1,3);
    Color col1(255, 255, 255);
    Circle c2(p1, 2, col1);
    Circle c3(p1,500, col1);
    cout << c2 << endl;
    Point p2(3,9);
    c2.setCenter(p2);
    c2.setRadius(3);
    c2.setRadius(-4);
    c2.setRadius(555);
    cout << c2.getCenter() << endl;
    cout << c2.getRadius() << endl;
    Circle c4;
    cout << "Expected: " << c3 << endl;
    Point p4(-1,89);
    Color col2(255, 255, 255);
    Circle c5(p4, 2, col2);
    cout << c5 << endl;
    Point p17(3,9);
    c2.setCenter(p17);
    c2.setRadius(68);
    cout << c2 << " " << c3;
    
    
}

void test_Triangle() {
    Triangle t1;
    Point p1(0,0);
    Point p2(1,2);
    Point p3(3,4);
    Color c1(1,1,1);
    Color c2(3, 4, 123);
    Color c3(45, 255, 0);
    Triangle t2(p1, p2, p3, c1);
    Triangle t3(p1, c1, p2, c2, p3, c3);
    cout << t1 << endl << t2 << endl << t3 << endl;
    cout << t2.getVertexOne() << endl << t2.getVertexTwo() << endl
    << t2.getVertexThree() << endl;
    cout << t2.getVertexOneColor() << t2.getVertexTwoColor() << endl <<  t2.getVertexThreeColor() << endl;
    t2.setColor(c2);
    t2.setVertexTwo(p3);
    t2.setVertexOne(p1);
    t2.setVertexThree(p2);
    cout << t1.getVertexOne() << endl << t1.getVertexTwo() << endl
    << t1.getVertexThree() << endl;
    cout << t1.getVertexOneColor() << t1.getVertexTwoColor() << endl <<  t1.getVertexThreeColor() << endl;
    
    
    
    
    
}




