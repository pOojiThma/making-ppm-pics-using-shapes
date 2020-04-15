#ifndef QUAD_H
#define QUAD_H

#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include "Shape.h"

using namespace std;

//Quadrilateral Class. derived class of Shape
class Quad : public Shape{
  private:
    int x;
    int y;
  public:
    //default constructor
    Quad();

    //virtual destructor
    virtual ~Quad();

    //setters
    void qSetX(int);
    void qSetY(int);

    //getters
    int qGetX();
    int qGetY();

    //virtual functions from Shape class
    virtual void readInfo(ifstream&);
    virtual int isHit(int, int);
    virtual void draw(Image&);
};

#endif
