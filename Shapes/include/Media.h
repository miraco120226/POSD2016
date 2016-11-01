#ifndef MEDIA_H
#define MEDIA_H
#include <string>
#include "MediaVisitor.h"

using namespace std;

class Rectangle;

class Media {
public :
    virtual double area() const = 0 ;
    virtual double perimeter() const = 0 ;
    virtual void accept(MediaVisitor * mv) = 0;
    virtual void add(Media * m);
};

#endif // MEDIA_H
