#include <iostream>
#include <cstdlib>
#include "Image.h"

int main(){
	Image solidColor(200,500);
	Image point(200,500);

	struct Color col(193, 84, 193);
	struct Color fill(0,0,200);
	struct Color clr(200, 0, 0);

	solidColor.fill(col);
	point.fill(fill);
	point.setColor(0,10, clr);
	point.setColor(1,10, clr);
	point.setColor(0,11, clr);
	point.setColor(1,11, clr);
	int success = saveImage(solidColor, "solid");
	success = saveImage(point, "point");
	return 0;
}