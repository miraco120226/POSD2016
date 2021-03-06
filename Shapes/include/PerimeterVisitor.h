#ifndef PERIMETERVISITOR_H
#define PERIMETERVISITOR_H
#include "MediaVisitor.h"

class PerimeterVisitor : public MediaVisitor{
    public:
        PerimeterVisitor (): perimeter(0) {}
        void visitShapeMedia(ShapeMedia *sm);
        void visitComboMediaPre(ComboMedia *cm);
        void visitComboMediaPost(ComboMedia *cm);
        double getPerimeter() const {return perimeter;}
    private:
        double perimeter;
};

#endif // PERIMETERVISITOR_H
