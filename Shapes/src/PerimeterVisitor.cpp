#include "PerimeterVisitor.h"
#include "ShapeMedia.h"
#include "ComboMedia.h"

void PerimeterVisitor::visitShapeMedia(ShapeMedia *sm){
    perimeter+=sm->getShape()->perimeter();
}

void PerimeterVisitor::visitComboMedia(ComboMedia *cm){


}
