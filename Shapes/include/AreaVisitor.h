#ifndef AREAVISITOR_H
#define AREAVISITOR_H
#include "MediaVisitor.h"

class AreaVisitor : public MediaVisitor{
    public:
        AreaVisitor (): area(0) {}
        void visitShapeMedia(ShapeMedia *sm);
        void visitComboMediaPre(ComboMedia *cm);
        void visitComboMediaPost(ComboMedia *cm);
        double getArea() const {return area;}
    private:
        double area;
};

#endif // AREAVISITOR_H
