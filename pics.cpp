/**
 * pics.cpp
 * Project UID 2e6ea4e086ea6a06753e819c30923369
 *
 * EECS 183
 * Project 4: CoolPics
 *
 * Rishi Baronia, Allen Shen
 * rbaronia, shenal
 *
 * Implements different functions using file I/O streams and the conventional open and closing statements of
 * the program. Is the main class of program
 */

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "Line.h"
#include "Triangle.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Graphics.h"

/**
 * Requires: Nothing.
 * Modifies: cout.
 * Effects:  Prints an opening message.
 */
void printOpener();

/**
 * Requires: Nothing.
 * Modifies: cout.
 * Effects:  Prints a closing message.
 */
void printCloser();

/**
 * Requires: Nothing.
 * Modifies: cout.
 * Effects:  Prints a menu.
 */
void printMenu();

/**
 * Requires: ins is in good state.
 * Modifies: cin, ins.
 * Effects:  Closes ins if it is open. Keeps reading filename from the user
 *           (and appends .txt) until the file is successfully opened.
 *           Returns the name of the file that was opened.
 */
string openFile(ifstream& ins);

/**
 * Requires: Nothing.
 * Modifies: Nothing.
 * Effects:  Returns str with all of its alphabetical characters lowercased.
 */
string tolower(string str);

/**
 * Requires: Nothing.
 * Modifies: cin, drawer.
 * Effects:
 *     Opens a file
 *     Start with a blank canvas (drawer)
 *     Start reading from file.  For each line....
 *        Read the 1st character to determine shape
 *        Read the shape:  L reads a line, C reads a circle, T read a triangle
 *            R reads a rectangle.
 *            For any other character, clears drawer and prints
 *            "Error in input file: " << [character already read]
 *            << [all chars remaining on the line] << endl;
 *        Draw shape on canvas
 *     Close file
 *     Print "[Loaded <filename>]", where <filename> is replaced with 
 *                                  the name of the file.
 */
void loadFile(Graphics& drawer);

/**
 * Requires: Nothing.
 * Modifies: cin, cout, drawer.
 * Effects:
 *     Read filename from user
 *     concatenate filename with .bmp
 *     Write image to file.
 *     Print "[Wrote filename]"
 */
void writeFile(const Graphics& drawer);

void coolPics()
{
    Graphics drawer;
    string command;
    printOpener();
    printMenu();

    // read first command from user
    cin >> command;
    cout << endl;
    command = tolower(command);

    // read user's input until he or she quits
    while (command != "quit")
    {
        if (command == "load")
        {
            loadFile(drawer);
        }
        else if (command == "write")
        {
            writeFile(drawer);
        }
        else
        {
            cout << "Invalid command" << endl << endl;
        }

        printMenu();

        // read next command
        cin >> command;
        cout << endl;
        command = tolower(command);
    }

    printCloser();
    
    return;
}

// adds .bmp to file name given by the user
void writeFile(const Graphics& drawer)
{
    // reads in file name and adds .bmp at the end
    string filename;
    cin >> filename;
    filename = filename + ".bmp";
    
    // writes the image to file
    drawer.writeFile(filename);
    cout << "[Wrote " << filename << "]"  << endl;
 
 
}



void loadFile(Graphics& drawer)
{
    ifstream load;
    
    string filename = openFile(load);
    string errorInp;
    Line l;
    Triangle t;
    Circle c;
    Rectangle r;
    char type;

    // checks what shape it is based on first character
    // c.draw draws the shape according to corresponding character
    while (load >> type) {


        if (type == 'L') {
            load >> l;
            l.draw(drawer);
        }
        else if (type == 'T') {
            load >> t;
            t.draw(drawer);
        }
        else if (type == 'C') {
            load >> c;
            c.draw(drawer);
        }
        else if (type == 'R') {
            load >> r;
            r.draw(drawer);
        }
        else {
            getline(load, errorInp);
            cout << "Error in input file: " << type
                 << errorInp << endl;
            drawer.clear();
            load.close();
        }
        
    
    }
    cout << "[Loaded " << filename << "]" << endl;
    load.close();
    
}

string tolower(string str)
{
    for (int i = 0; i < str.length(); i++) {
        str.at(i) = tolower(str.at(i));
    }
    return str;
}


// Don't change the implementations below!

void printMenu()
{
    cout << "Command:            Description:" << endl
         << "--------            ------------" << endl
         << "load filename       Loads data from a txt file" << endl
         << "write filename      Creates a bmp image from data" << endl
         << "quit                Quits the program" << endl << endl;
}


void printOpener()
{
    cout << "=================================================" << endl
         << "               Welcome to CoolPics" << endl
         << "=================================================" << endl << endl;
}

void printCloser()
{
    cout << "=================================================" << endl
         << "            Thanks for using CoolPics!" << endl
         << "=================================================" << endl;
}

string openFile(ifstream& ins)
{
    string fileName;

    // close stream if open
    if (ins.is_open())
    {
        ins.clear();
        ins.close();
    }

    // get filename
    cin >> fileName;
    fileName = fileName + ".txt";
    ins.open(fileName);

    // keep retrying if failed to open
    while (ins.fail())
    {
        cout << "Error in opening " << fileName
             << ". Enter another file name: ";
        ins.clear();
        cin >> fileName;
        fileName = fileName + ".txt";
        ins.open(fileName);
    }

    return fileName;
}
