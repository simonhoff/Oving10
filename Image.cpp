#include "Image.h"

/*****************************************************
 * You _should_ change the functions in this file.   *
 * The following functions are provided so that      *
 * the code will compile, note however that the      *
 * program will not run before you have implemented  *
 * all the functions in this file.                   *
 *****************************************************/

Image::Image( unsigned int width, unsigned int height ) {
   data = new unsigned char*[height];
   for (int row = 0; row < height; row++ ){
   		*(data + row) = new unsigned char[width * 3];
   		}
   	}
   	this->height = height;
   	this->width = width;
}

Image::~Image()  {
   	for (int row = 0; row < height; row++ ){
   		delete[] *(data + row);
   	}
   	delete[] data;
   	data = nullptr;
}

unsigned int Image::getWidth() const {
   return this->width;
}
unsigned int Image::getHeight() const  { 
   return this->height;
}

const unsigned char * Image::getScanLine(unsigned int line) const  {
   /* Enter your code here */
   return (data + line);
}
unsigned char * Image::getScanLine(unsigned int line) {
   return (data + line);
}

Color Image::getColor( unsigned int x, unsigned int y ) const {
   struct Color retColor();
   retColor.r = *(*(data + y) + x*3);
   retColor.g = *(*(data + y) + x*3 + 1);
   retColor.b = *(*(data + y) + x*3 + 2);
   return retColor;
}
void Image::setColor( unsigned int x, unsigned int y, const Color &color ) {
	unsigned char address = *(*(data + y) + 3*x);
	*(address++) = color.r;
	*(address++) = color.g;
	*(address) = color.b;
}

void Image::fill( const Color &color ) {
 	for (int row = 0; row < height; row++ )
 		for (int col = 0; col < width; col++ )
 			setColor(col, row, color);
 }
