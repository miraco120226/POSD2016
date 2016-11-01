#include "TextMedia.h"

double TextMedia::area() const{
    return txt->getRectangle().area();
};

double TextMedia::perimeter() const{
    return txt->getRectangle().perimeter();
};

void TextMedia::accept(MediaVisitor * mv){

};

Text* TextMedia::getText() const{
    return txt;
};

