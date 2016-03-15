#include <cstdlib>
#include <vector>
#include "Image.h"
#include "shape.h"
#include "canvas.h"

void Canvas::addShape(Shape* s){
	shapes.push_back(s);
}

void Canvas::rasterizeTo(Image &img){
	for (auto itr = shapes.begin(); itr != shapes.end(); itr++){
		(*itr)->draw(img);
	}
}

void Canvas::clear(){
	for (auto itr = shapes.begin(); itr != shapes.end(); itr++){
		delete *itr;
	}
}
