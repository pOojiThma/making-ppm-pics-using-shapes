#ifndef IMAGE_H
#define IMAGE_H
#include "Header.h"
#include "Pixel.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

//image class declaration
class Image{
  private:
    Header head;
    vector< vector<Pixel> >vec2D;
  public:
    //constructors and destructors
    Image();
    ~Image();

    //member functions prototypes
    void writeHeader(ofstream&);
    void write_p6(ofstream&);
    vector< vector<Pixel> >& getVec();
    Header getHeader();
};
#endif
