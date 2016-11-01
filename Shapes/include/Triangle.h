#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Shapes.h"
#include <math.h>
#include <string>
#include <sstream>

using namespace std;

class Triangle : public Shape{
public:
    Triangle(double x1,double y1,double x2,double y2,double x3,double y3):
        ax(x1),ay(y1),bx(x2),by(y2),cx(x3),cy(y3){}
    double ab_length() const;
    double bc_length() const;
    double ca_length() const;
    double perimeter() const;
    double area() const;
    bool islegal();
    string description() const;

private:
    double ax,ay,bx,by,cx,cy;
};

#endif // TRIANGLE_H
