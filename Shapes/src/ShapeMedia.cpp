#include "ShapeMedia.h"

double ShapeMedia::area() const {
     return shape->area();
}

double ShapeMedia::perimeter() const {
     return shape->perimeter();
}

void ShapeMedia::accept(MediaVisitor * mv) {
    mv->visitShapeMedia(this);
}

Shape * ShapeMedia::getShape()const {
    return shape;
}
