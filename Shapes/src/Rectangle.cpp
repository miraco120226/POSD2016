#include "Rectangle.h"

double Rectangle::area() const {
    return l*w;
}

double Rectangle::perimeter() const{
    return l+w+l+w;
}

bool Rectangle::islegal(){
    return (l>0)&&(w>0);
}
