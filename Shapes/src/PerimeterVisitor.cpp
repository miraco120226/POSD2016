#include "PerimeterVisitor.h"
#include "ShapeMedia.h"
#include "ComboMedia.h"

void PerimeterVisitor::visitShapeMedia(ShapeMedia *sm){
    perimeter+=sm->getShape()->perimeter();
}

void PerimeterVisitor::visitComboMediaPre(ComboMedia *cm){


}

void PerimeterVisitor::visitComboMediaPost(ComboMedia *cm){


}
