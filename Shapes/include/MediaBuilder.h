#ifndef MEDIABUILDER_H
#define MEDIABUILDER_H

#include <Shapes.h>
#include <Media.h>

class MediaBuilder
{
    public:
        virtual void buildComboMedia() = 0;
        virtual void buildShapeMedia(Shape * s) = 0;
        virtual Media *getMedia()= 0;

};

#endif // MEDIABUILDER_H
