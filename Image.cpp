#include "Image.h"

/*****************************************************
 * You _should_ change the functions in this file.   *
 * The following functions are provided so that      *
 * the code will compile, note however that the      *
 * program will not run before you have implemented  *
 * all the functions in this file.                   *
 *****************************************************/

Image::Image( unsigned int width, unsigned int height ):width(width), height(height) {
   data = new unsigned char*[height];
   for (int row = 0; row < height; row++ ){
   		*(data + row) = new unsigned char[width * 3];
   	}
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
   if (line < height) return *(data + line);
}
unsigned char * Image::getScanLine(unsigned int line) {
   if (line < height) return *(data + line);
}

Color Image::getColor( unsigned int x, unsigned int y ) const {
	if (x < width && y < height){   
	   struct Color retColor;
   		retColor.red = *(*(data + y) + x*3);
	   	retColor.green = *(*(data + y) + x*3 + 1);
   		retColor.blue = *(*(data + y) + x*3 + 2);
   		return retColor;
   	}else{
   		struct Color col;
   		return col;
   	}
}
void Image::setColor( unsigned int x, unsigned int y, const Color &color ) {
	if (x < width && y < height){
		unsigned char* address = *(data + y) + 3*x;
		*(address++) = color.red;
		*(address++) = color.green;
		*(address) = color.blue;
	}
}

void Image::fill( const Color &color ) {
 	for (int row = 0; row < height; row++ )
 		for (int col = 0; col < width; col++ )
 			setColor(col, row, color);
 }
