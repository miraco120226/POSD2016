#include "AreaVisitor.h"
#include "ShapeMedia.h"
#include "ComboMedia.h"

void AreaVisitor::visitShapeMedia(ShapeMedia *sm){
    area+=sm->getShape()->area();
}

void AreaVisitor::visitComboMediaPre(ComboMedia *cm){


}

void AreaVisitor::visitComboMediaPost(ComboMedia *cm){


}
