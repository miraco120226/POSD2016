#ifndef COMBOMEDIABUILDER_H
#define COMBOMEDIABUILDER_H

#include "MediaBuilder.h"

class ComboMediaBuilder : public MediaBuilder
{
    public:
        ComboMediaBuilder() : cm(0) {};
        void buildComboMedia();
        void buildShapeMedia(Shape * s);
        void buildAddShapeMedia(ShapeMedia * sm);
        void buildAddComboMedia(ComboMedia * cm);
        Media *getMedia();
    private:
        ComboMedia* cm;
};

#endif // COMBOMEDIABUILDER_H
