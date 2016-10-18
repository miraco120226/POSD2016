#include "Triangle.h"

double Triangle::ab_length() const {
    return sqrt((bx-ax)*(bx-ax)+(by-ay)*(by-ay));
}

double Triangle::bc_length() const {
    return sqrt((cx-bx)*(cx-bx)+(cy-by)*(cy-by));
}

double Triangle::ca_length() const {
    return sqrt((ax-cx)*(ax-cx)+(ay-cy)*(ay-cy));
}

double Triangle::perimeter() const{
    return ab_length()+bc_length()+ca_length();
}

double Triangle::area() const {
    double const s=perimeter()/2;
    return sqrt(s*(s-ab_length())*(s-bc_length())*(s-ca_length()));
}

bool Triangle::islegal(){
    return area();
}
