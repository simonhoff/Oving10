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
	double r = radius;
	double dTheta = 1/(4*3.14*r);
	double theta = 0;
	while (theta < 2 * 3.14){
		int xPos, yPos;
		xPos = (int) ((int) x) + r*std::cos(theta);
		yPos = (int) ((int) y) + r*std::sin(theta);
		img.setColor(xPos, yPos, getColor());
		theta += dTheta;
	}

}
