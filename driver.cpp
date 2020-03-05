/*
Ramneek Chhatwal
rchhatw
CPSC 1020 Sec 001, F18
rchhatw@g.clemson.edu
PA3 - FROSTY THE SNOWMAN'S BEACH ADVENTURE
*/

#include "Shape.h"
#include "Circle.h"
#include "Color.h"
#include "Point.h"
#include "Image.h"
#include "Triangle.h"
#include "Quad.h"
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char const *argv[]) {
  //opening input and output files
  ifstream input(argv[1]);
  ofstream output(argv[2]);

  string inputName;

  //error checking to see if enough command line arguments were given
  if (argc != 3) {
    exit(1);
  }

  //error checking to see if files opened correctly
  if (!input.is_open() || !output.is_open()) {
    exit(1);
  }

  //creating an instance of the Image class using the default constructor
  Image img;

  while (!input.eof()) {
    input >> inputName;

    if (inputName == "Circle") {
      /*creating a pointer of the Abstract base class, Shape, that is pointing to
      the circle class object.*/
      Shape* shCirc1 = new Circle;

      /*calling the readInfo virtual function from the circle Shape pointer to read
      the dimensions of the circle object that is going to be printed.*/
      shCirc1->readInfo(input);

      /*calling the draw virtual function from the circle Shape pointer to set the
      2D vector of pixels to the appropriate RGB values.*/
      shCirc1->draw(img);
      delete shCirc1;
    }

    if (inputName == "Triangle") {
      /*creating a pointer of the Abstract base class, Shape, that is pointing to
      the triangle class object.*/
      Shape* shTri1 = new Triangle;

      /*calling the readInfo virtual function from the triangle Shape pointer to
      read the dimensions of the triangle object that is going to be printed.*/
      shTri1->readInfo(input);

      /*calling the draw virtual function from the circle Shape pointer to set the
      2D vector of pixels to the appropriate RGB values.*/
      shTri1->draw(img);
      delete shTri1;
    }

    if (inputName == "Quadrilateral") {
      /*creating a pointer of the Abstract base class, Shape, that is pointing to
      the quad class object.*/
      Shape* shQuad1 = new Quad;

      /*calling the readInfo virtual function from the quad Shape pointer to
      read the dimensions of the quad object that is going to be printed.*/
      shQuad1->readInfo(input);

      /*calling the draw virtual function from the quad Shape pointer to set the
      2D vector of pixels to the appropriate RGB values.*/
      shQuad1->draw(img);
      delete shQuad1;
    }
  }

  /*calling the write_p6 function to set the pixels in the 2D vector to the
  output ppm file*/
  img.write_p6(output);

  //closing input and output files
  input.close();
  output.close();

  return 0;
}
