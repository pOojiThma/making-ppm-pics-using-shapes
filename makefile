CC=g++
CFLAGS=-Wall -g -std=c++11 -o PA3
compile:
	$(CC) $(CFLAGS) driver.cpp Header.cpp Image.cpp Pixel.cpp Shape.cpp Circle.cpp Triangle.cpp Point.cpp Color.cpp Quad.cpp
run:
	./PA3 ShapeDef.txt output.ppm
clean:
	rm PA3 output.ppm
