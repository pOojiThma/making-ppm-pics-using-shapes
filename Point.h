/*
Ramneek Chhatwal
rchhatw
CPSC 1020 Sec 001, F18
rchhatw@g.clemson.edu
PA3 - FROSTY THE SNOWMAN'S BEACH ADVENTURE
*/


#ifndef POINT_H
#define POINT_H

//point class declaration
class Point{
  private:
    double x, y;
  public:
    //Point regular constructor
    Point(int, int);

    //Point setters
    void ptSetX(double);
    void ptSetY(double);

    //Point getters
    double ptGetX();
    double ptGetY();
};
#endif
