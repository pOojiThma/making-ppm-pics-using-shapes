#include "Circle.h"

//This is the default constructor
Circle::Circle() : centerX(1), centerY(1), radius(1){
}

//This is the regular constructor
Circle::Circle(int x, int y, int r) : centerX(x), centerY(y), radius(r){
}

//virtual destructor for the circle class object
Circle::~Circle(){

}

/*function to set the x values.  input is the xVal from the file.  There is no
return for this function.*/
void Circle::setX(int xVal){
  centerX = xVal;
}

/*function to set the y values. input is the yVal from the file.  There is no
return for this funtion.*/
void Circle::setY(int yVal){
  centerY = yVal;
}

/*function to set the radius value.  input is the rad from the file. There is
no return for this function*/
void Circle::setR(int rad){
  radius = rad;
}

/*function to return the x value from the class.  There is no input.  The
output is an int which is the value of the x in the private section of the
class*/
int Circle::getX(){
  return centerX;
}

/*function to return the y value from the class.  There is no input.  The
output is an int which is the value of the y in the private section of the
class*/
int Circle::getY(){
  return centerY;
}

/*function to return the r value from the class.  There is no input.  The
output is an int which is the value of the r in the private section of the
class*/
int Circle::getR(){
  return radius;
}

/*This function will read the info from the text file that is inputted. readInfo
is a virtual class from the base abstract class, Shape.  It will read the text
file and set the points for the circle in the pts vector.  It will also set the
RGB values for the color in the color class. The input for this function is the
 input text file that will be read from.  There is no output for this function*/
void Circle::readInfo(ifstream& in){
  int newX = 0;
  int newY = 0;
  int newRad = 0;

  //reading in from input file and setting the circle values
  in >> newX >> newY >> newRad;
  setX(newX);
  setY(newY);
  setR(newRad);

  pts.push_back(Point(newX, newY));

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
the circle or not.  This will be used to set the RBG values to the 2D vector.
The input for this function is the x and y value for the test point.  The output
of the function will be a 1 if the point is wihin the circle or 0 if it is
outside.*/
int Circle::isHit(int x, int y){
  int check = 0;

  if ((x-centerX) * (x-centerX) + (y-centerY) * (y-centerY) <= (radius*radius)){
    check = 1;
  }
  else {
    check = 0;
  }
  return check;
}

/*This function will loop through each pixel in the image and call the isHit
function.  If isHit is true, then the colors set for the object will be set to
the pixel 2D vector.  The input for this function is the instance of the image
class.  There is no output for this function.*/
void Circle::draw(Image& im){
  int hit = 0;

  for (int i = 0; i < im.getHeader().getHeight(); i++){
    for (int j = 0; j < im.getHeader().getWidth(); j++){
      //calling hit function to see if x and y points are within the circle
      hit = isHit(j,i);

      if (hit == 1) {
        //setting the color of the object to the 2D vec if points are in circle
        im.getVec().at(i).at(j).setR(c.getMainRed());
        im.getVec().at(i).at(j).setG(c.getMainGreen());
        im.getVec().at(i).at(j).setB(c.getMainBlue());
      }
    }
  }
}
