#pragma once 

#include "Image.h"

class Shape{
private:
	struct Color clr;
public:
	Shape(struct Color &col);
	virtual void draw(Image &img) = 0;
	struct Color getColor();
};

class Line: public Shape{
private:
	unsigned int x1, x2, y1, y2;
public:
	Line(unsigned int x1, unsigned int x2, unsigned int y1, unsigned int y2, struct Color col);
	virtual void draw(Image &img);
};

class Rectangle: public Shape{
private:
	int height, width;
public:

};

class Circle: public Shape{
private:
	int radius;
public:

};
