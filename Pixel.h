#ifndef PIXEL_H
#define PIXEL_H
#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>

//pixel class declaration
class Pixel{
  private:
    unsigned char r,g,b;
  public:
  //constructors and destructors
    Pixel();
    Pixel(unsigned char, unsigned char, unsigned char);
    ~Pixel();

    //setters
    void setR (int red);
    void setG (int green);
    void setB (int blue);

    //getters
    int getR ();
    int getG ();
    int getB ();
};

#endif
