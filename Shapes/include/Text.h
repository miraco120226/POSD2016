#ifndef TEXT_H
#define TEXT_H
#include <string>
#include "Rectangle.h"

using namespace std;

class Text{

    public:
        Text(Rectangle boundingbox, string text ):rec(boundingbox),txt(text){};
        string getText() const;
        Rectangle getRectangle() const;
    private:
        Rectangle rec;
        string txt;
};

#endif // TEXT_H
