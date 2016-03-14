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

Line::Line(unsigned int x1, unsigned int x2, unsigned int y1, unsigned int y2, struct Color col): Shape::Shape(col){
	this->x1 = x1; this->x2 = x2;
	this->y1 = y1; this->y2 = y2;
}

void Line::draw(Image &img){
	if (x1 < x2){
		double a = ((double)y2-(double)y1)/((double)x2-(double)x1);
		std::cout << x1 << " " << x2 << " " << y1 << " " << y2 << std::endl;
		std::cout << "a= " << a << std::endl;
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
