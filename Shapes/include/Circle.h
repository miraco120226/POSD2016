#ifndef CIRCLE_H
#define CIRCLE_H
#include "Shapes.h"

class Circle : public Shape{
public:
    Circle(double centerX,double centerY,double radius):
        cx(centerX),cy(centerY),r(radius){}
    double area()const;
    double perimeter() const;
    bool islegal();

private:
    double cx,cy,r;
    double const PI=3;
};

#endif // CIRCLE_H
