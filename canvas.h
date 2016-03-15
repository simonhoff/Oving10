#pragma once

#include <vector>
#include "Image.h"
#include "shape.h"


class Canvas{
private:
	std::vector<Shape*> shapes;
public:
	void addShape(Shape* s);
	void rasterizeTo(Image &img);
	void clear();
};
