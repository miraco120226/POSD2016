#ifndef SHAPEMEDIABUILDER_H
#define SHAPEMEDIABUILDER_H

#include "MediaBuilder.h"

class ShapeMediaBuilder : public MediaBuilder
{
    public:
        ShapeMediaBuilder() : sm(0) {};
        void buildComboMedia();
        void buildShapeMedia(Shape * s);
        Media *getMedia();
    private:
        ShapeMedia* sm;
};

#endif // SHAPEMEDIABUILDER_H
