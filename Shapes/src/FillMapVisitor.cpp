#include "FillMapVisitor.h"

void FillMapVisitor::visitShapeMedia(ShapeMedia *sm){
    string name;
    ss>>name;

    if(mediaMap->count(name)!=0 /*&& sm!=mediaMap[name]*/){
        throw string("the name of shape is already existed");
    }

    mediaMap->insert(pair<string, Media*>(name,(Media*)sm));
}

void FillMapVisitor::visitComboMediaPre(ComboMedia *cm){
    string name;
    ss>>name;

    if(mediaMap->count(name)!=0/* && cm!=mediaMap[name]*/){
        throw string("the name of combo is already existed");
    }

    mediaMap->insert(pair<string, Media*>(name,(Media*)cm));
}

void FillMapVisitor::visitComboMediaPost(ComboMedia *cm){

}

map<string, Media*>* FillMapVisitor::getMap(){
    return mediaMap;
}

