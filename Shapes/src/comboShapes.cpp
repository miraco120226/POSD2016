#include "comboShapes.h"

comboShapes::comboShapes(Shape* shape1,Shape* shape2){
    shapes.push_back(shape1);
    shapes.push_back(shape2);
}

comboShapes::comboShapes(vector<Shape*> input){
    shapes.assign(input.begin(),input.end());
}

double comboShapes::area() const {
    return sumOfArea(shapes);
}

double comboShapes::perimeter() const {
    return sumOfPerimeter(shapes);
}

bool comboShapes::islegal(){

}

void comboShapes::add(Shape* shape){

    shapes.push_back(shape);
}

bool comboShapes::del(Shape* shape){

    vector<Shape*>::iterator result=find(shapes.begin(),shapes.end(),shape);
    if(result == shapes.end() || shapes.size()<=2){
        return false;
    }
    else{
        shapes.erase(result);
        return true;
    }
}
