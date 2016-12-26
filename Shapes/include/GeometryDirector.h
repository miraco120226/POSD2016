#ifndef GEOMETRYDIRECTOR_H
#define GEOMETRYDIRECTOR_H
#include <stack>
#include <map>
#include <vector>
#include <sstream>
#include <iostream>
#include "MediaBuilder.h"
#include "ComboMediaBuilder.h"
#include "ShapeMediaBuilder.h"
#include "Shapes.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "comboShapes.h"
#include "Media.h"
#include "ShapeMedia.h"
#include "ComboMedia.h"
using namespace std;

class GeometryDirector
{
    public :
		void concrete(string line1,string line2);
        map<string, Media*> getMap();
	private :
    	map<string, Media*> mediaMap;
};

#endif // GEOMETRYDIRECTOR_H
