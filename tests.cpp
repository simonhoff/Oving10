#include <iostream>
#include <cstdlib>
#include "Image.h"
#include "shape.h"

int main(){
	Image solidColor(200,500);
	Image line(200,500);

	struct Color col(193, 84, 193);
	struct Color fill(0xFF,0xFF,0xFF);
	struct Color clr(200, 0, 0);

	Shape* l = new Line(70, 150, 450, 440, clr);
	line.fill(fill);
	l->draw(line); 

	solidColor.fill(col);

	int success = saveImage(solidColor, "solid");
	success = saveImage(line, "line");
	return 0;
}