#ifndef DESCRIPTIONVISITOR_H
#define DESCRIPTIONVISITOR_H
#include <string>
#include "MediaVisitor.h"

using namespace std;

class DescriptionVisitor : public MediaVisitor{
    public:
        DescriptionVisitor (): description(string("")) {}
        void visitShapeMedia(ShapeMedia *sm);
        void visitComboMediaPre(ComboMedia *cm);
        void visitComboMediaPost(ComboMedia *cm);
        string getDescription() const {return description;}
    private:
        string description;
};

#endif // DESCRIPTIONVISITOR_H
