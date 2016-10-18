#ifndef COMBOMEDIA_H
#define COMBOMEDIA_H
#include<vector>
#include "Media.h"
#include "MediaVisitor.h"

class ComboMedia : public Media {
private:
    std::vector<Media*> media;
public:
    ComboMedia( std::vector<Media*> m ) : media(m) {}
    double area( ) const;
    double perimeter( ) const;
    void accept(MediaVisitor * mv) {
        for(Media *m: media){
            m->accept(mv);
        }
        mv->visitComboMedia(this);
    }
    void add (Media *m);
};

#endif // COMBOMEDIA_H
