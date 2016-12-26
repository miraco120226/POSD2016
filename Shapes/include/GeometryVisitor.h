#ifndef GEOMETRYVISITOR_H
#define GEOMETRYVISITOR_H
#include "MediaVisitor.h"
#include "Media.h"
#include <map>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

class GeometryVisitor : public MediaVisitor{
    public:
        GeometryVisitor (map<string, Media*> *mmap): mediaMap(mmap) {}
        void visitShapeMedia(ShapeMedia *sm);
        void visitComboMediaPre(ComboMedia *cm);
        void visitComboMediaPost(ComboMedia *cm);
        string getDescription() const {return desc;}
    private:
        map<string, Media*> *mediaMap;
        string desc;
};

#endif // GEOMETRYVISITOR_H
