/*
Ramneek Chhatwal
rchhatw
CPSC 1020 Sec 001, F18
rchhatw@g.clemson.edu
PA3 - FROSTY THE SNOWMAN'S BEACH ADVENTURE
*/


#include "Pixel.h"

//default constructor to set rgb values
Pixel::Pixel() : r(120), g(225), b(240){
}

//regular constructor to set rgb values to input values
Pixel::Pixel(unsigned char red, unsigned char green, unsigned char blue) :
r(red), g(green), b(blue){
}

//destructor
Pixel::~Pixel(){
}

//implementation of setting the red pixel
void Pixel::setR(int red){
  r = static_cast<unsigned char> (red);
}

//implementation of setting the green pixel
void Pixel::setG(int green){
  g = static_cast<unsigned char> (green);
}

//implementation of setting the blue pixel
void Pixel::setB(int blue){
  b = static_cast<unsigned char> (blue);
}

//implementation of getting the red pixel
int Pixel::getR(){
  return r;
}

//implementation of getting the green pixel
int Pixel::getG(){
  return g;
}

//implementation of getting the blue pixel
int Pixel::getB(){
  return b;
}
