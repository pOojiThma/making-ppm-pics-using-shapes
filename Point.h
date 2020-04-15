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
