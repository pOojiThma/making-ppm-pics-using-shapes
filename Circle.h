#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"
#include "Image.h"

using namespace std;

//circle class. derived class from Shape
class Circle : public Shape{
  private:
    int centerX;
    int centerY;
    int radius;
  public:
    //defualt constructor
    Circle();

    //virtual destructor
    virtual ~Circle();

    //regular constructor
    Circle(int, int, int);

    //setters
    void setX(int xval);
    void setY(int yval);
    void setR(int rad);

    //getters
    int getX();
    int getY();
    int getR();

    //virtual functions
    virtual void readInfo(ifstream&);
    virtual int isHit(int, int);
    virtual void draw(Image&);
};

#endif
