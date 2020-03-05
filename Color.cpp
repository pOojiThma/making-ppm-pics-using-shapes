/*
Ramneek Chhatwal
rchhatw
CPSC 1020 Sec 001, F18
rchhatw@g.clemson.edu
PA3 - FROSTY THE SNOWMAN'S BEACH ADVENTURE
*/


#include "Color.h"

Color::Color() : mainR(0), mainG(0), mainB(0), backR(0), backG(0), backB(0) {
}

void Color::setMainRed(unsigned char r){
  mainR = r;
}

void Color::setMainGreen(unsigned char g){
  mainG = g;
}
void Color::setMainBlue(unsigned char b){
  mainB = b;
}

unsigned char Color::getMainRed(){
  return mainR;
}

unsigned char Color::getMainGreen(){
  return mainG;
}

unsigned char Color::getMainBlue(){
  return mainB;
}
