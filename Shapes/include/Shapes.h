#ifndef SHAPES_H
#define SHAPES_H

#include <string>
using namespace std;

class Shape {
public:
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual bool islegal() = 0;
    string name;
};

#endif // SHAPES_H
