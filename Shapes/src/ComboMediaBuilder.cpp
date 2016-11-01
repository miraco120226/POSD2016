#include "ComboMediaBuilder.h"
#include "ShapeMedia.h"
#include "ComboMedia.h"
#include <iostream>
using namespace std;

void ComboMediaBuilder::buildComboMedia(){
    cm=new ComboMedia();
};

void ComboMediaBuilder::buildShapeMedia(Shape * s){

};

void ComboMediaBuilder::buildAddShapeMedia(ShapeMedia* sm){
    cm->add(sm);
};

void ComboMediaBuilder::buildAddComboMedia(ComboMedia* cmi){
    cm->add(cmi);
};

Media* ComboMediaBuilder::getMedia(){
    return cm;
};
