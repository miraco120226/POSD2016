#ifndef CIRCLE_H
#define CIRCLE_H
#include "Shapes.h"
#include <string>
#include <sstream>

using namespace std;

class Circle : public Shape{
public:
    Circle(double centerX,double centerY,double radius):
        cx(centerX),cy(centerY),r(radius){}
    double area()const;
    double perimeter() const;
    bool islegal();
    string description() const;

private:
    double cx,cy,r;
    double const PI=3;
};

#endif // CIRCLE_H
