#ifndef FILLMAPVISITOR_H
#define FILLMAPVISITOR_H
#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include "MediaVisitor.h"
#include "DescriptionVisitor.h"
#include "Media.h"
#include "ShapeMedia.h"
#include "ComboMedia.h"
using namespace std;

class FillMapVisitor : public MediaVisitor{
    public:
        FillMapVisitor (string s): mediaMap(new map<string, Media*>),input(s){ss<<s;}
        void visitShapeMedia(ShapeMedia *sm);
        void visitComboMediaPre(ComboMedia *cm);
        void visitComboMediaPost(ComboMedia *cm);
        map<string, Media*>* getMap();
    private:
        map<string, Media*> *mediaMap;
        string input;
        stringstream ss;
};

#endif // FILLMAPVISITOR_H
