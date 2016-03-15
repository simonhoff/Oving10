#include <iostream>
#include <cstdlib>
#include <new>
#include "Image.h"
#include "shape.h"
#include "canvas.h"

int main(){
	Image solidColor(200,500);
	Image line(200,500);

	struct Color col(193, 84, 193);
	struct Color fill(0xFF,0xFF,0xFF);
	struct Color clr(200, 0, 0);

	Shape* l = new Line(70, 150, 450, 440, clr);
	Shape* c = new Circle(50,50,40,clr);
	Shape* r = new Rectangle(30,40,250,100,clr);
	line.fill(fill);
	c->draw(line); 

	solidColor.fill(col);

	int success = saveImage(solidColor, "solid");
	success = saveImage(line, "line");
	delete l;
	delete c;
	delete r;
	l = r = c = nullptr;
	//smiley
	Image smiley(300, 400);
	smiley.fill(fill);

	struct Color yellow(0xFF ,0xCC,0x77);
	struct Color black(0,0,0);

	Shape* face = new Circle(150,200,100,yellow);
	Shape* eye1 = new Circle(130,220,10, black);
	Shape* eye2 = new Circle(170,220,10, black);
	Shape* mouth = new Curve(150,180,30,4,1.4, 5, black);

	Canvas smile;
	smile.addShape(face);
	smile.addShape(eye1);
	smile.addShape(eye2);
	smile.addShape(mouth);

	smile.rasterizeTo(smiley);
	success = saveImage(smiley,"smiley");

	delete face;
	delete eye1;
	delete eye2;
	delete mouth;
	face = eye1 = eye2 = mouth = nullptr;

	//mustache picture
	Image *mustache = loadImage("lena512.bmp");

	Canvas stache;
	int x0 = mustache->getWidth()/2 + 25;
	int y0 = mustache->getHeight()/3 +20;
	for (int x = x0; x < x0 + 40; x += 2){
		Shape* hair = new Line(x,x,y0-5-((x-(x0+20))*(x-(x0+20))/30),y0-20,black);
		stache.addShape(hair);
	}
	stache.rasterizeTo(*mustache);
	success = saveImage(*mustache, "mustache");

	stache.clear();

	delete mustache;
	return 0;
}