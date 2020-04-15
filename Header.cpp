#include "Header.h"

//default constructor to set header equal to a 400 x 400 P6 PPM equivalent
Header::Header() : magicNum("P6"), width(400), height(400), maxVal(255){
}

//regular constructor to set header to input parameters
Header::Header(string name, int w, int h, int max) : magicNum(name), width(w),
height(h), maxVal(max){
}

//destructor
Header::~Header(){
}

//implementation for setting the magic number from the header
void Header::setMagicNum(string name){
  magicNum = name;
}

//implementation for setting the width from the header
void Header::setWidth(int w){
  width = w;
}

//implementation for setting the height from the header
void Header::setHeight(int h){
  height = h;
}

//implementation for setting the max value from the header
void Header::setMaxVal(int val){
  maxVal = val;
}

//implementation for getting the magic number from the header
string Header::getMagicNum(){
  return magicNum;
}

//implementation for getting the width from the header
int Header::getWidth(){
  return width;
}

//implementation for getting the height from the header
int Header::getHeight(){
  return height;
}

//implementation for getting the max value from the header
int Header::getMaxVal(){
  return maxVal;
}
