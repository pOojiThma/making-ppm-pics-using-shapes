/*
Ramneek Chhatwal
rchhatw
CPSC 1020 Sec 001, F18
rchhatw@g.clemson.edu
PA3 - FROSTY THE SNOWMAN'S BEACH ADVENTURE
*/


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
