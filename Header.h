#ifndef HEADER_H
#define HEADER_H
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdlib.h>
using namespace std;

//Header class declaration
class Header{
  private:
    string magicNum;
    int width;
    int height;
    int maxVal;
  public:
    //constructors and destructors
    Header();
    Header(string, int, int, int);
    ~Header();

    //setters
    void setMagicNum(string name);
    void setWidth(int w);
    void setHeight(int h);
    void setMaxVal(int val);

    //getters
    string getMagicNum();
    int getWidth();
    int getHeight();
    int getMaxVal();
};
#endif
