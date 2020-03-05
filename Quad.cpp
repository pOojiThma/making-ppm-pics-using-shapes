/*
Ramneek Chhatwal
rchhatw
CPSC 1020 Sec 001, F18
rchhatw@g.clemson.edu
PA3 - FROSTY THE SNOWMAN'S BEACH ADVENTURE
*/


#include "Shape.h"
#include "Quad.h"

//implementation for the default constructor
Quad::Quad() : x(0), y(0){

}

//virtual destructor for the Quad object
Quad::~Quad(){

}

//implementation for the x value setter
void Quad::qSetX(int xval) {
  x = xval;
}

//implementation for the y value setter
void Quad::qSetY(int yval){
  y = yval;
}

//implementation for the x value getter
int Quad::qGetX(){
  return x;
}

//implementation for the y value getter
int Quad::qGetY(){
  return y;
}

/*This function will read the info from the text file that is inputted. readInfo
is a virtual class from the base abstract class, Shape.  It will read the text
file and set the points for the quad in the pts vector.  It will also set
the RGB values for the color in the color class. The input for this function is
the input text file that will be read from.  There is no output for this
function*/
void Quad::readInfo(ifstream& in){
  double x = 0;
  double y = 0;

  for (int i = 0; i < 4; i++){
    //reading in from input file and setting the quad values
    in >> x >> y;
    pts.push_back(Point(x, y));
  }

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
the quad or not.  This will be used to set the RBG values to the 2D vector.
The input for this function is the x and y value for the test point.  The output
of the function will be a 1 if the point is wihin the quad or 0 if it is
outside.*/
int Quad::isHit(int x, int y){
  double a = 0.0;
  double b = 0.0;
  double c = 0.0;

  double nX = static_cast<double>(x);
  double x1 = 0.0;
  double x2 = 0.0;
  double x3 = 0.0;

  double nY = static_cast<double>(y);
  double y1 = 0.0;
  double y2 = 0.0;
  double y3 = 0.0;

  for (int i = 0; i < 3; i++){
    x1 = pts.at(i).ptGetX();
    y1 = pts.at(i).ptGetY();
    x2 = pts.at(i+1).ptGetX();
    y2 = pts.at(i+1).ptGetY();

    if (i == 2) {
      x3 = pts.at(0).ptGetX();
      y3 = pts.at(0).ptGetY();
    }
    else {
      x3 = pts.at(i+2).ptGetX();
      y3 = pts.at(i+2).ptGetY();
    }

    a = ((y2-y3)*(nX-x3)+(x3-x2)*(nY-y3))/((y2-y3)*(x1-x3)+(x3-x2)*(y1-y3));
    b = ((y3-y1)*(nX-x3)+(x1-x3)*(nY-y3))/((y2-y3)*(x1-x3)+(x3-x2)*(y1-y3));
    c = 1 - a - b;

    if ((( a >= 0 && a <= 1) && (b >= 0 && b <= 1) && (c >= 0 && c <= 1))) {
      return 1;
    }
  }
  return 0;
}

/*This function will loop through each pixel in the image and call the isHit
function.  If isHit is true, then the colors set for the object will be set to
the pixel 2D vector.  The input for this function is the instance of the image
class.  There is no output for this function.*/
void Quad::draw(Image& im){
  int hit = 0;

  for (int i = 0; i < im.getHeader().getHeight(); i++){
    for (int j = 0; j < im.getHeader().getWidth(); j++){
      //calling hit function to see if x and y points are within the quad
      hit = isHit(j,i);

      //setting the color of the object to the 2D vec if points are in quad
      if (hit == 1) {
        im.getVec().at(i).at(j).setR(c.getMainRed());
        im.getVec().at(i).at(j).setG(c.getMainGreen());
        im.getVec().at(i).at(j).setB(c.getMainBlue());
      }
    }
  }
}
