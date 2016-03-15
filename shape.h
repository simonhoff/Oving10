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
	Line(unsigned int x1, unsigned int x2, unsigned int y1, unsigned int y2, struct Color &col);
	virtual void draw(Image &img);
};

class Rectangle: public Shape{
private:
	unsigned int height, width, x, y;
public:
	Rectangle(unsigned int x, unsigned int y, unsigned int height, unsigned int width, struct Color &col); 
	virtual void draw(Image &img);
};

class Circle: public Shape{
private:
	unsigned int radius, x, y;
public:
	Circle(unsigned int x, unsigned int y, unsigned int radius, struct Color &col);
	virtual void draw(Image &img);
};

class Curve: public Shape{
private:
	unsigned int radius, x, y, thickness;
	double a0, angle;
public:
	Curve(unsigned int x, unsigned int y, unsigned int radius, double a0, double angle, unsigned int thickness, struct Color &col);
	virtual void draw(Image &img);
};
