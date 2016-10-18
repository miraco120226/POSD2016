#ifndef AREAVISITOR_H
#define AREAVISITOR_H
#include "MediaVisitor.h"

class AreaVisitor : public MediaVisitor{
public:
    AreaVisitor (): area(0) {}
    void visitShapeMedia(ShapeMedia *sm);
    void visitComboMedia(ComboMedia *cm);
    double getArea() const {return area;}
private:
    double area;
};

#endif // AREAVISITOR_H
