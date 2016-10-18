#ifndef MEDIAVISITOR_H
#define MEDIAVISITOR_H

class ComboMedia;
class ShapeMedia;

class MediaVisitor{
public:
    virtual void visitShapeMedia(ShapeMedia *sm)=0;
    virtual void visitComboMedia(ComboMedia *cm)=0;

};

#endif // MEDIAVISITOR_H
