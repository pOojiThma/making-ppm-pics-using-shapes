/*
Ramneek Chhatwal
rchhatw
CPSC 1020 Sec 001, F18
rchhatw@g.clemson.edu
PA3 - FROSTY THE SNOWMAN'S BEACH ADVENTURE
*/


#include "Image.h"

//implementation of Image defualt constructor
Image::Image(){
  head.setMagicNum("P6");
  head.setWidth(500);
  head.setHeight(500);
  head.setMaxVal(255);

  vec2D.resize(head.getHeight(), vector<Pixel>(head.getWidth()));
}

//implementation of Image destructor
Image::~Image(){
}

//implementation of Image 2D vector getter
vector< vector<Pixel> >& Image::getVec(){
  return vec2D;
}

//implementation of image Header getter
Header Image::getHeader(){
  return head;
}

/*This function will write the private members from the header object in the
Image class to the output file by using getters.  The input for this function
is the output file pointer.  There is no output for this function.*/
void Image::writeHeader(ofstream& outFile){
  outFile << head.getMagicNum() << " " << head.getWidth() << " ";
  outFile << head.getHeight() << " " << head.getMaxVal() << " ";
}

/*This function will write the contents of the output file.  It will call the
writeHeader function to print out the header contents to the output file.  It
will then print the pixels from the 2D vector to the output file.  The input
for this function is the output file pointer.  There is no output for this
function.*/
void Image::write_p6(ofstream& outFile){
  //calling writeHeader function to output header to output file
  writeHeader(outFile);

  //for loop to print contents of the 2D vector
  for (int i = 0; i < (int)vec2D.size(); i++) {
    for (int j = 0; j < (int)vec2D.at(i).size(); j++) {
      outFile << (unsigned char)vec2D.at(i).at(j).getR();
      outFile << (unsigned char)vec2D.at(i).at(j).getG();
      outFile << (unsigned char)vec2D.at(i).at(j).getB();
    }
  }
}
