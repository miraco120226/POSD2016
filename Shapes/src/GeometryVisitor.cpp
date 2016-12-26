#include "GeometryVisitor.h"

void GeometryVisitor::visitShapeMedia(ShapeMedia *sm){
    string name;
    for (auto &i : *mediaMap) {
      if (i.second == (Media*)sm) {
         name = i.first;
         break;
      }
    }
    desc=desc+name+string(" ");
}

void GeometryVisitor::visitComboMediaPre(ComboMedia *cm){
    string name;
    for (auto &i : *mediaMap) {
      if (i.second == (Media*)cm) {
         name = i.first;
         break;
      }
    }
    desc=desc+name+string("{");
}

void GeometryVisitor::visitComboMediaPost(ComboMedia *cm){
    desc=desc+string("} ");
}
