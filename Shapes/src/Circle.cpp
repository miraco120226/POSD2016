#include "Circle.h"

double Circle::area()const {
    return PI*r*r;
}

double Circle::perimeter() const{
    return 2*PI*r;
}

bool Circle::islegal() {
    return (r>0);
}

string Circle::description() const {
    stringstream ss;
    ss << "c("
        << cx << " " << cy << " "
        << r << ") ";
    return ss.str();
}

