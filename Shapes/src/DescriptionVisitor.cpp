#include "DescriptionVisitor.h"
#include "ShapeMedia.h"
#include "ComboMedia.h"
#include <iostream>

void DescriptionVisitor::visitShapeMedia(ShapeMedia *sm){
    description+=sm->getShape()->description();
}

void DescriptionVisitor::visitComboMediaPre(ComboMedia *cm){
    description+="combo(";
}

void DescriptionVisitor::visitComboMediaPost(ComboMedia *cm){
    description+=")";
}
