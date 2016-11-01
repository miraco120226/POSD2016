#include "ShapeMediaBuilder.h"
#include <ShapeMedia.h>

void ShapeMediaBuilder::buildComboMedia(){

};

void ShapeMediaBuilder::buildShapeMedia(Shape * s){
    sm=new ShapeMedia(s);
};

Media* ShapeMediaBuilder::getMedia(){
    return sm;
};
