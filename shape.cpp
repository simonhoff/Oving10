#include <cstdlib>
#include <cmath>
#include <iostream>
#include "Image.h"
#include "shape.h"

Shape::Shape(struct Color &col){
	this->clr = col;
}
struct Color Shape::getColor(){
	return this->clr;
}

Line::Line(unsigned int x1, unsigned int x2, unsigned int y1, unsigned int y2, struct Color &col): Shape::Shape(col){
	this->x1 = x1; this->x2 = x2;
	this->y1 = y1; this->y2 = y2;
}

void Line::draw(Image &img){
	if (x1 < x2){
		double a = ((double)y2-(double)y1)/((double)x2-(double)x1);
		unsigned int currentY, previousY;
		previousY = currentY = y1;
		for (int x = x1; x < x2; x++){
			currentY =  floor(a*(x - x1) + y1);
			if (currentY >= previousY){
				for (int y = previousY; y < currentY + 1; y++ ){
					img.setColor(x, y, getColor());
				}
			}else{
				for (int y = previousY; y > currentY - 1; y-- ){
					img.setColor(x, y, getColor());
				}
			}
			previousY = currentY;
		}
	}else if (x1 > x2){
		double a = ((double)y2-(double)y1)/((double)x1-(double)x2);
		unsigned int currentY, previousY;
		currentY = y1;
		for (int x = x2; x < x1; x++){
			currentY =  floor(a*(x - x2) + y1);
			if (currentY >= previousY){
				for (int y = previousY; y < currentY + 1; y++ ){
					img.setColor(x, y, getColor());
				}
			}else{
				for (int y = previousY; y > currentY - 1; y-- ){
					img.setColor(x, y, getColor());
				}
			}
			previousY = currentY;
		}
	}else if (x1 == x2){
		for (int y = std::min(y1,y2); y < std::max(y1, y2); y++){
			img.setColor(x1, y, getColor());
		}
	}
}

Rectangle::Rectangle(unsigned int x, unsigned int y, unsigned int height, unsigned int width, struct Color &col):Shape::Shape(col){
	this->x = x; this->y = y;
	this->height = height;
	this->width = width;
} 

void Rectangle::draw(Image &img){
	for (int xpos = x; xpos < x +width; xpos++){
		for (int ypos = y; ypos < y + height; ypos++){
			img.setColor(xpos, ypos, getColor());
		}
	}
}

Circle::Circle(unsigned int x, unsigned int y, unsigned int radius, struct Color &col):Shape::Shape(col){
	this->x = x; this->y = y;
	this->radius = radius;
}

void Circle::draw(Image &img){
	for (int xPos = x - radius; xPos < x + radius; xPos++){
		int yStart = (int) y - (int) sqrt(radius*radius -(xPos - x)*(xPos - x));
		int yFin = (int) y + (int) sqrt(radius*radius -(xPos - x)*(xPos - x));
		for (int yPos = yStart; yPos < yFin + 1; yPos++){
			img.setColor(xPos, yPos, getColor());
		}
	}
}

Curve(unsigned int x, unsigned int y, unsigned int radius, double a0, double angle, struct Color &col):	Shape::Shape(),
																										x(x),
																										y(y),
																										radius(radius),
																										a0(a0),
																										angle(angle)
{}

virtual void draw(Image &img){
	double theta = a0;
	double dTheta = 1/(4*angle*radius);
	while (theta < a0+angle){
		int xPos, yPos;
		xPos = x + radius*cos(theta);
		yPos = y + radius*sin(theta);

		img.setColor(xPos, yPos, getColor());

		theta += dTheta;
	}
}
