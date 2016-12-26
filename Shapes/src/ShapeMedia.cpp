#include "ShapeMedia.h"
#include <iostream>
double ShapeMedia::area() const {
     return shape->area();
}

double ShapeMedia::perimeter() const {
     return shape->perimeter();
}

void ShapeMedia::accept(MediaVisitor * mv) {
    mv->visitShapeMedia(this);
}

void ShapeMedia::add(Media * m) {
    throw std::string("Illegal: add on ShapeMedia");
};

void ShapeMedia::removeMedia (Media *m) {
    throw std::string("Illegal: remove from ShapeMedia");
};

bool ShapeMedia::removeMediaByRef (Media *m) {
    throw std::string("Illegal: remove from ShapeMedia");
};

Shape * ShapeMedia::getShape()const {
    return shape;
}
