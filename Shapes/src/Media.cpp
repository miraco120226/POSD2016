#include "Media.h"

void Media::add(Media * m) {
    throw std::string("Illegal: add on media");
};

void Media::removeMedia (Media *m) {
    throw std::string("Illegal: remove from media");
};

bool Media::removeMediaByRef (Media *m) {
    throw std::string("Illegal: remove from media");
};
