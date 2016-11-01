#ifndef SHAPEMEDIA_H
#define SHAPEMEDIA_H
#include "Shapes.h"
#include "Media.h"
#include "Text.h"

class ShapeMedia : public Media {

    private:
        Shape* shape ;
    public :
        ShapeMedia( Shape* s ): shape(s) {}
        void accept(MediaVisitor * mv);
        double area() const;
        double perimeter() const;
        Shape * getShape() const;
};

#endif // SHAPEMEDIA_H
