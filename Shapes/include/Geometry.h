#ifndef GEOMETRY_H
#define GEOMETRY_H
#include <iostream>
#include <map>
#include <sstream>
#include <fstream>
#include <io.h>
#include "Media.h"
#include "MediaDirector.h"
#include "AreaVisitor.h"
#include "PerimeterVisitor.h"
#include "GeometryVisitor.h"
#include "DescriptionVisitor.h"
#include "FillMapVisitor.h"
#include "GeometryDirector.h"



using namespace std;

class Geometry
{
    public:
        bool run();
        map<string, Media*> mediaMap;
};

#endif // GEOMETRY_H
