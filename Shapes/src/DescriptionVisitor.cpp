#include "DescriptionVisitor.h"
#include "ShapeMedia.h"
#include "ComboMedia.h"
#include <iostream>

void DescriptionVisitor::visitShapeMedia(ShapeMedia *sm){
    description+=sm->getShape()->description();
}

void DescriptionVisitor::visitComboMedia(ComboMedia *cm){
    description="combo("+description+")";
}
