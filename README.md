# making-ppm-pics-using-shapes
This project is designed to use the PPM image structure and create a user-defined picture using only the endpoints for a square, triangle, and quadrilateral that the user inputs into a text file as well as the rgb values to add color. 

I made this program to demonstrate my ability in using PPM images, abstract classes, and polymorphism.  

The driver for this program is under driver.cpp.

To create the shapes that will be inserted into the user's picture:
  In a text file, format each shape in the follow order (keeping in mind point (0,0) is botttom left of the screen):
  
    //for Quadrilateral
    Quadrilateral
    x-coordinate y-coordinate 
    x-coordinate y-coordinate 
    x-coordinate y-coordinate 
    x-coordinate y-coordinate 
    r (rgb val) g (rgb val) b (rgb val)
    
    //for Circle
    Circle
    x-coordinate y-coordinate (for center point)
    radius 
    r (rgb val) g (rgb val) b (rgb val)
    
    //for Triangle
    Triangle
    x-coordinate y-coordinate 
    x-coordinate y-coordinate
    x-coordinate y-coordinate
    r (rgb val) g (rgb val) b (rgb val)
    
An example for a valid textfile that will work is provided as ShapeDef.txt with a sample output shown as output.ppm

A makefile is provided to use.  It's current state requires that the text file that provides the shape definitions is called ShapeDef.txt.  It will output the image under the file output.ppm.  However, these values can be changed within the makefile. 

In order to deploy this project using the makefile, all files, including makefile, need to be in the same directory.
  To compile: enter in the terminal "make"
  To run: enter in the terminal "make run"
  To remove the created output file: enter in the terminal "make clean" 


