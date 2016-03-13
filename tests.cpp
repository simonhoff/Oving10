#include <iostream>
#include <cstdlib>
#include "Image.h"
#include "ImageIO.cpp"

int main(){
	Image solidColor(200,300);
	Image point(200,300);
	solidColor.fill(struct Color col(193,84,193));
	point.setColor(10,10,struct Color clr(200,0,0));
	int success = saveImage(solidColor, "solid");
	success = saveImage(point, "point");
	return 0;
}