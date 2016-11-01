#ifndef TEXTMEDIA_H
#define TEXTMEDIA_H
#include "Media.h"
#include "Text.h"

class TextMedia : public Media{

    private:
        Text* txt;
    public:
        TextMedia(Text* input): txt(input) {}
        double area() const;
        double perimeter() const;
        void accept(MediaVisitor * mv);
        Text* getText() const;

};

#endif // TEXTMEDIA_H
