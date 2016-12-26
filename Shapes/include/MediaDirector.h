#ifndef MEDIADIRECTOR_H
#define MEDIADIRECTOR_H
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
#include <stack>
#include <sstream>
#include <iostream>
using namespace std;

class MediaDirector{
    public :
		void setMediaBuilder(stack<MediaBuilder *> *mbs);
		void concrete(string content);
	private :
    		stack<MediaBuilder *> *mb;
};


#endif // MEDIADIRECTOR_H
