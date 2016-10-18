#ifndef COMBOSHAPES_H
#define COMBOSHAPES_H

#include "Shapes.h"
#include "Functions.h"
#include <vector>

using namespace std;

class comboShapes : public Shape{
    public:
        comboShapes(Shape* shape1,Shape* shape2);
        comboShapes(vector<Shape*> input);
        double area() const;
        double perimeter() const;
        bool islegal();
        void add(Shape* shape);
        bool del(Shape* shape);
//    private:
        vector<Shape*> shapes;
};

#endif // COMBOSHAPES_H
