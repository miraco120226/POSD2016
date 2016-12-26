#include "ComboMedia.h"
#include "DescriptionVisitor.h"
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

double ComboMedia::area( ) const {
        double total =0;
            for (Media *m: media)
                total += m->area();
        return total;
}

double ComboMedia::perimeter( ) const {
        double total =0;
            for (Media *m: media)
                total += m->perimeter();
        return total;
}

void ComboMedia::accept(MediaVisitor * mv) {

        mv->visitComboMediaPre(this);
        for(Media *m: media){
            m->accept(mv);
        }
        mv->visitComboMediaPost(this);
}

void ComboMedia::add (Media *m) {
        media.push_back(m);
}


void ComboMedia::removeMedia (Media *m) {
        DescriptionVisitor dv;
        m->accept(&dv);

        for(vector<Media*>::iterator iter=media.begin();iter!=media.end();iter++){
            DescriptionVisitor dv2;
            (*iter)->accept(&dv2);

            //cout<<"media1:"<<dv.getDescription()<<endl;
            //cout<<"media2:"<<dv2.getDescription()<<endl;

            if(dv2.getDescription().substr(0,5)=="combo"){
                ((ComboMedia*)(*iter))->removeMedia(m);
            }
            else if(dv2.getDescription()==dv.getDescription()){
                --(iter=media.erase(iter));
            }
        }
}
bool ComboMedia::removeMediaByRef (Media *m) {
        bool isExist=false;
        for(vector<Media*>::iterator iter=media.begin();iter!=media.end();iter++){
            DescriptionVisitor dv;
            (*iter)->accept(&dv);

            if(*iter==m){
                --(iter=media.erase(iter));
                isExist=true;
            }
            else if(dv.getDescription().substr(0,5)=="combo"){
                isExist=((ComboMedia*)(*iter))->removeMediaByRef(m);
            }
        }
        return isExist;
}

vector<Media*> ComboMedia::getMedia(){
    return media;
}

