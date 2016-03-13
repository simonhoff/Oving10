#include "Image.h"

/*****************************************************
 * You _should_ change the functions in this file.   *
 * The following functions are provided so that      *
 * the code will compile, note however that the      *
 * program will not run before you have implemented  *
 * all the functions in this file.                   *
 *****************************************************/

Image::Image( unsigned int width, unsigned int height ) {
   data = new unsigned char**[height];
   for (int row = 0; row < height; row++ ){
   		*(data + row) = new unsigned char*[width];
   		for (int col = 0; col < width; col++){
   			*(*(data + row) + col) = new unsigned char[3];
   		}
   	}
   	this->height = height;
   	this->width = width;
}

Image::~Image()  {
   /* Enter your code here */
}

unsigned int Image::getWidth() const {
   /* Enter your code here */
   return 0;
}
unsigned int Image::getHeight() const  {
   /* Enter your code here */ 
   return 0;
}

const unsigned char * Image::getScanLine(unsigned int line) const  {
   /* Enter your code here */
   return nullptr;
}
unsigned char * Image::getScanLine(unsigned int line) {
   /* Enter your code here */
   return nullptr;
}

Color Image::getColor( unsigned int x, unsigned int y ) const {
   /* Enter your code here */
   return Color();
}
void Image::setColor( unsigned int x, unsigned int y, const Color &color ) {
   /* Enter your code here */
}

void Image::fill( const Color &color ) {
   /* Enter your code here */
}
