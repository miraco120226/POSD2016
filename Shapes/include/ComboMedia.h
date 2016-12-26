#ifndef COMBOMEDIA_H
#define COMBOMEDIA_H
#include<vector>
#include "Media.h"
#include "MediaVisitor.h"

class ComboMedia : public Media {
public:
    ComboMedia( std::vector<Media*> m ) : media(m) {}
    ComboMedia() {}
    double area( ) const;
    double perimeter( ) const;
    void accept(MediaVisitor * mv);
    void add (Media *m);
    void removeMedia (Media *m);
    bool removeMediaByRef (Media *m);
    vector<Media*> getMedia();

private:
    std::vector<Media*> media;
};

#endif // COMBOMEDIA_H
