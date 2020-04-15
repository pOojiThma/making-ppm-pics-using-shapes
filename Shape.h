#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <cmath>
#include <sstream>
#include "Point.h"
#include "Color.h"
#include "Image.h"

using namespace std;

//Shape class.  Is a base class and abstract
class Shape{
  protected:
    Color c;
    string name;
    vector<Point> pts;
  public:
    //default constructor
    Shape();

    //virtual destructor
    virtual ~Shape() = 0;

    //pure virtual functions
    virtual void readInfo(ifstream&) = 0;
    virtual int isHit(int, int) = 0;
    virtual void draw(Image&) = 0;
};

#endif
