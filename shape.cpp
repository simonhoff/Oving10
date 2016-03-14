#include <cstdlib>
#include <cmath>

Shape::Shape(struct Color &col){
	this->clr = col;
}

pure virtual Shape::draw(Image &img){

}

Line::Line(unsigned int x1, unsigned int x2, unsigned int y1, unsigned int y2, struct Color col): Shape::Shape(col){
	this->x1 = x1; this->x2 = x2;
	this->y1 = y1; this->y2 = y2;
}

pure virtual Line::draw(Image &img){
	if (x1 < x2){
		double a = (y2-y1)/(x2-x1);
		unsigned int currentY, previousY;
		currentY = y1;
		for (int x = x1; x < x2; x++){
			currentY =  floor(a*(x-x1)+y1);
			if (currentY >= previousY){
				for (int y = previousY; y < currentY + 1; y++ ){
					img.setColor(x, y, this->clr);
				}
			}else{
				for (int y = previousY; y > currentY - 1; y-- ){
					img.setColor(x, y, this->clr);
				}
			}
			previousY = currentY;
}
