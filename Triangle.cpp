#include "Triangle.h"

//implementation for default constructor
Triangle::Triangle(){
  x = 0;
  y = 0;
}

//implementation for regular constructor
Triangle::Triangle(double x1, double y1){
  x = x1;
  y = y1;
}

//virtual destructor for the triangle object
Triangle::~Triangle(){

}

//implementation for X value setter
void Triangle::setX(double xVal){
  x = xVal;
}

//implementation for Y value setter
void Triangle::setY(double yVal){
  y = yVal;
}

//implementation for X value getter
double Triangle::getX(){
  return x;
}

//implementation for Y value getter
double Triangle::getY(){
  return y;
}

/*This function will read the info from the text file that is inputted. readInfo
is a virtual class from the base abstract class, Shape.  It will read the text
file and set the points for the triangle in the pts vector.  It will also set
the RGB values for the color in the color class. The input for this function is
the input text file that will be read from.  There is no output for this
function*/
void Triangle::readInfo(ifstream& in){
  int ax = 0;
  int ay = 0;
  int bx = 0;
  int by = 0;
  int cx = 0;
  int cy = 0;

  //reading in from input file and setting the triangle values
  in >> ax >> ay >> bx >> by >> cx >> cy;
  pts.push_back(Point(ax,ay));
  pts.push_back(Point(bx,by));
  pts.push_back(Point(cx,cy));

  int newRed = 0;
  int newGreen = 0;
  int newBlue = 0;

  //reading pixels from input file and setting the color
  in >> newRed >> newGreen >> newBlue;
  c.setMainRed(static_cast<unsigned char>(newRed));
  c.setMainBlue(static_cast<unsigned char>(newBlue));
  c.setMainGreen(static_cast<unsigned char>(newGreen));
}

/*This function will check to see if the test point that is provided is within
the triangle or not.  This will be used to set the RBG values to the 2D vector.
The input for this function is the x and y value for the test point.  The output
of the function will be a 1 if the point is wihin the triangle or 0 if it is
outside.*/
int Triangle::isHit(int x, int y){
  double a = 0.0;
  double b = 0.0;
  double c = 0.0;

  //getting the values for the Triangles
  double nX = static_cast<double>(x);
  double nY = static_cast<double>(y);
  double x1 = pts.at(0).ptGetX();
  double y1 = pts.at(0).ptGetY();
  double x2 = pts.at(1).ptGetX();
  double y2 = pts.at(1).ptGetY();
  double x3 = pts.at(2).ptGetX();
  double y3 = pts.at(2).ptGetY();

  a = ((y2-y3)*(nX-x3)+(x3-x2)*(nY-y3))/((y2-y3)*(x1-x3)+(x3-x2)*(y1-y3));
  b = ((y3-y1)*(nX-x3)+(x1-x3)*(nY-y3))/((y2-y3)*(x1-x3)+(x3-x2)*(y1-y3));
  c = 1 - a - b;

  if ((( a >= 0 && a <= 1) && (b >= 0 && b <= 1) && (c >= 0 && c <= 1))) {
    return 1;
  }
  else {
    return 0;
  }
}

/*This function will loop through each pixel in the image and call the isHit
function.  If isHit is true, then the colors set for the object will be set to
the pixel 2D vector.  The input for this function is the instance of the image
class.  There is no output for this function.*/
void Triangle::draw(Image& im){
  int hit = 0;

  for (int i = 0; i < im.getHeader().getHeight(); i++){
    for (int j = 0; j < im.getHeader().getWidth(); j++){
      //calling hit function to see if x and y points are within the triangle
      hit = isHit(j,i);

      //setting the color of the object to the 2D vec if points are in triangle
      if (hit == 1) {
        im.getVec().at(i).at(j).setR(c.getMainRed());
        im.getVec().at(i).at(j).setG(c.getMainGreen());
        im.getVec().at(i).at(j).setB(c.getMainBlue());
      }
    }
  }
}
