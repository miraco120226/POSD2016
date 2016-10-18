#include "ComboMedia.h"

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

void ComboMedia::add (Media *m) {
        media.push_back(m);
}
