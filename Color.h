#ifndef COLOR_H
#define COLOR_H

#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

//color class declaration
class Color {
  private:
    unsigned char mainR;
    unsigned char mainG;
    unsigned char mainB;
  public:
    //color defualt constructor
    Color();

    //color setters
    void setMainRed(unsigned char);
    void setMainGreen(unsigned char);
    void setMainBlue(unsigned char);

    //color getters
    unsigned char getMainRed();
    unsigned char getMainGreen();
    unsigned char getMainBlue();
};
#endif
