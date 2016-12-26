#include "Functions.h"

double sumOfPerimeter(vector<Shape*> shapes){
    double sum=0;
    for(Shape* s:shapes){
        sum+=s->perimeter();
    }
    return sum;
}

double sumOfArea(vector<Shape*> shapes){
    double sum=0;
    for(Shape* s:shapes){
        sum+=s->area();
    }
    return sum;
}

vector<Shape*>& maxArea(vector<Shape*> shapes){
    static vector<Shape*> max;
    //vector<Shape*> max;
    max.clear();
    max.push_back(shapes.at(0));
    for(Shape* s:shapes){
        if(s->area() > max.at(0)->area()){
            max.clear();
            max.push_back(s);
        }
        else if(s->area() == max.at(0)->area()){
            max.push_back(s);
        }
    }
    return max;
}

bool isLarger(const Shape* x,const Shape* y){
    return x->perimeter()<y->perimeter();
}

void sortByDecreasingPerimeter(vector<Shape*> &shapes){
    sort(shapes.begin(),shapes.end(),isLarger);
}

void runGeometry(){
    Geometry geo;

    while (true){
        try{
            if(!geo.run())
                break;
        }
        catch (string s){
            cout<<s<<endl<<endl;
        }
    }
}
