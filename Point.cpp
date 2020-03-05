/*
Ramneek Chhatwal
rchhatw
CPSC 1020 Sec 001, F18
rchhatw@g.clemson.edu
PA3 - FROSTY THE SNOWMAN'S BEACH ADVENTURE
*/


#include "Point.h"

//implementation of Point regular constructor
Point::Point(int xval, int yval){
  x = xval;
  y = yval;
}

//implementation of Point x setter
void Point::ptSetX(double xval){
  x = xval;
}

//implementation of Point y setter
void Point::ptSetY(double yval){
  y = yval;
}

//implementation of Point x getter
double Point::ptGetX(){
  return x;
}

//implementation of Point y getter
double Point::ptGetY(){
  return y;
}
