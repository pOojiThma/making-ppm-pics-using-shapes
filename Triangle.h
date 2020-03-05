/*
Ramneek Chhatwal
rchhatw
CPSC 1020 Sec 001, F18
rchhatw@g.clemson.edu
PA3 - FROSTY THE SNOWMAN'S BEACH ADVENTURE
*/


#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include "Shape.h"

using namespace std;

//Triangle class declaration.  derived class of Shape
class Triangle : public Shape {
  //creating private variables that can only be called by member functions.
  private:
    double x;
    double y;
  public:
    //declaring constructors and destructors
    Triangle();
    Triangle(double, double);

    //virtual destructor
    virtual ~Triangle();

    //declaring setters and getters
    void setX(double);
    void setY(double);
    double getX();
    double getY();

    //virtual function prototypes
    virtual void readInfo(ifstream&);
    virtual int isHit(int, int);
    virtual void draw(Image&);
};

#endif
