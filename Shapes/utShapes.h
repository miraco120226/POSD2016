#ifndef UTSHAPES_H_INCLUDED
#define UTSHAPES_H_INCLUDED

#include "..\cppunitlite\TestHarness.h"
#include "Shapes.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Functions.h"
#include "comboShapes.h"
#include "Media.h"
#include "ShapeMedia.h"
#include "ComboMedia.h"
#include "MediaVisitor.h"
#include "AreaVisitor.h"
#include "PerimeterVisitor.h"

#include <vector>
#include <math.h>

const double epsilon = 0.00001;
// added this line
TEST (islegal, Rectangle) {
    Rectangle rect(0,0,2,3);
    CHECK_EQUAL(true,rect.islegal());
}

TEST (area, Rectangle) {
    Rectangle rect(0,0,2,3);
    DOUBLES_EQUAL(6,rect.area(),epsilon);
}

TEST (perimeter, Rectangle) {
    Rectangle rect(0,0,2,3);
    DOUBLES_EQUAL(10,rect.perimeter(),epsilon);
}

TEST (islegal, Circle) {
    Circle circ(0,0,2);
    CHECK_EQUAL(true,circ.islegal());
}

TEST (area, Circle) {
    Circle circ(0,0,2);
    DOUBLES_EQUAL(12,circ.area(),epsilon);
}

TEST (perimeter, Circle) {
    Circle circ(0,0,2);
    DOUBLES_EQUAL(12,circ.perimeter(),epsilon);
}

TEST (islegal, Triangle) {
    Triangle tri(0,0,5,0,0,12);
    CHECK_EQUAL(true,tri.islegal());
}

TEST (area, Triangle) {
    Triangle tri(0,0,5,0,0,12);
    DOUBLES_EQUAL(30,tri.area(),epsilon);
}

TEST (perimeter, Triangle) {
    Triangle tri(0,0,5,0,0,12);
    DOUBLES_EQUAL(30,tri.perimeter(),epsilon);
}

TEST (first, sumOfPerimeter) {
    Triangle tri(0,0,3,0,0,4);//per=12
    Circle circ(0,0,2);       //per=12
    Rectangle rect(0,0,2,3);  //per=10
    vector<Shape*> s{&tri,&circ,&rect};
    DOUBLES_EQUAL(34,sumOfPerimeter(s),epsilon);
}

TEST (second, sumOfArea) {
    Triangle tri(0,0,3,0,0,4);//area=6
    Circle circ(0,0,3);       //area=27
    Rectangle rect(0,0,4,3);  //area=12
    vector<Shape*> s{&tri,&circ,&rect};
    DOUBLES_EQUAL(45,sumOfArea(s),epsilon);
}

TEST (third, maxArea) {
    Triangle tri(0,0,3,0,0,4);//area=6
    Circle circ(0,0,3);       //area=27
    Rectangle rect(0,0,4,3);  //area=12
    vector<Shape*> s{&tri,&circ,&rect};
    vector<Shape*>& maxarea=maxArea(s);
    CHECK_EQUAL(&circ,*(find(maxarea.begin(),maxarea.end(),&circ)));
}

TEST (forth, sortByDecreasingPerimeter) {
    Triangle tri(0,0,3,0,0,4);//per=12
    Circle circ(0,0,3);       //per=18
    Rectangle rect(0,0,4,3);  //per=14
    Triangle tri2(0,0,5,0,0,12);//per=30
    Circle circ2(0,0,4);       //per=24
    Rectangle rect2(0,0,4,5);  //per=20
    vector<Shape*> s{&tri,&circ,&rect,&tri2,&circ2,&rect2};
    vector<Shape*> s2{&tri,&rect,&circ,&rect2,&circ2,&tri2};
    sortByDecreasingPerimeter(s);
    CHECK_EQUAL(true,equal(s.begin(),s.end(),s2.begin()));
}

TEST (perimeter, comboShapes) {
    Triangle tri(0,0,3,0,0,4);//per=12
    Circle circ(0,0,3);       //per=18
    Rectangle rect(0,0,4,3);  //per=14
    Triangle tri2(0,0,5,0,0,12);//per=30
    Circle circ2(0,0,2);       //per=12
    comboShapes s1(&tri,&circ);
    comboShapes s2(&rect,&tri2);
    s1.add(&s2);
    s1.add(&circ2);
    DOUBLES_EQUAL(86,s1.perimeter(),epsilon);
}

TEST (area, comboShapes) {
    Triangle tri(0,0,3,0,0,4);//area=6
    Circle circ(0,0,3);       //area=27
    Rectangle rect(0,0,4,3);  //area=12
    Triangle tri2(0,0,5,0,0,12);//area=30
    Circle circ2(0,0,2);       //area=12
    comboShapes s1(&tri,&circ);
    comboShapes s2(&rect,&tri2);
    s1.add(&s2);
    s1.add(&circ2);
    DOUBLES_EQUAL(87,s1.area(),epsilon);
}

TEST (vector_perimeter, comboShapes) {
    Triangle tri(0,0,3,0,0,4);//per=12
    Circle circ(0,0,3);       //per=18
    Rectangle rect(0,0,4,3);  //per=14
    vector<Shape*> s{&tri,&circ,&rect};
    comboShapes s1(s);
    DOUBLES_EQUAL(44,s1.perimeter(),epsilon);
}

TEST (area, ShapeMedia) {
    Triangle tri(0,0,3,0,0,4);//area=6
    ShapeMedia sm(&tri);
    DOUBLES_EQUAL(6,sm.area(),epsilon);
}

TEST (area, ComboMedia) {
    Triangle tri(0,0,3,0,0,4);//area=6
    Circle circ(0,0,3);       //area=27
    Rectangle rect(0,0,4,3);  //area=12
    ShapeMedia s1(&tri);
    ShapeMedia s2(&circ);
    ShapeMedia s3(&rect);
    vector<Media*> vm{&s1,&s2,&s3};
    ComboMedia cm(vm);
    DOUBLES_EQUAL(45,cm.area(),epsilon);
}

TEST (perimeter, ShapeMedia) {
    Triangle tri(0,0,3,0,0,4);//per=12
    ShapeMedia sm(&tri);
    DOUBLES_EQUAL(12,sm.perimeter(),epsilon);
}

TEST (perimeter, ComboMedia) {
    Triangle tri(0,0,3,0,0,4);//per=12
    Circle circ(0,0,2);       //per=12
    Rectangle rect(0,0,2,3);  //per=10
    ShapeMedia s1(&tri);
    ShapeMedia s2(&circ);
    ShapeMedia s3(&rect);
    vector<Media*> vm{&s1,&s2,&s3};
    ComboMedia cm(vm);
    DOUBLES_EQUAL(34,cm.perimeter(),epsilon);
}

TEST (Regular_hexagon_area, ComboMedia) {
    Triangle tri1(0,0,-1,sqrt(3),0,2*sqrt(3));//area=sqrt(3)/2
    Triangle tri2(2,0,3,sqrt(3),2,2*sqrt(3));//area=sqrt(3)/2
    Rectangle rect(0,0,2,2*sqrt(3));//area=4*sqrt(3)
    ShapeMedia s1(&tri1);
    ShapeMedia s2(&tri2);
    ShapeMedia s3(&rect);
    vector<Media*> vm{&s1,&s2,&s3};
    ComboMedia rh(vm);
    DOUBLES_EQUAL(6*sqrt(3),rh.area(),epsilon);
}

TEST (Regular_hexagon_perimeter, ComboMedia) {
    Triangle tri1(0,0,-1,sqrt(3),0,2*sqrt(3));//perimeter=4+2*sqrt(3)
    Triangle tri2(2,0,3,sqrt(3),2,2*sqrt(3));//perimeter=4+2*sqrt(3)
    Rectangle rect(0,0,2,2*sqrt(3));//perimeter=4+4*sqrt(3)
    ShapeMedia s1(&tri1);
    ShapeMedia s2(&tri2);
    ShapeMedia s3(&rect);
    vector<Media*> vm{&s1,&s2,&s3};
    ComboMedia rh(vm);
    DOUBLES_EQUAL(12+8*sqrt(3),rh.perimeter(),epsilon);
}

TEST (AreaVisitor, ComboMedia) {
    Triangle tri1(0,0,-1,sqrt(3),0,2*sqrt(3));//area=sqrt(3)/2
    Triangle tri2(2,0,3,sqrt(3),2,2*sqrt(3));//area=sqrt(3)/2
    Rectangle rect(0,0,2,2*sqrt(3));//area=4*sqrt(3)

    ShapeMedia s1(&tri1);
    ShapeMedia s2(&rect);
    vector<Media*> vm1{&s1,&s2};
    ComboMedia rh1(vm1);

    ShapeMedia s3(&tri2);
    vector<Media*> vm2{&s3,&rh1};
    ComboMedia rh2(vm2);

    AreaVisitor av;
    rh2.accept(&av);
    DOUBLES_EQUAL(6*sqrt(3),av.getArea(),epsilon);
}

TEST (PerimeterVisitor, ComboMedia) {
    Triangle tri1(0,0,-1,sqrt(3),0,2*sqrt(3));//perimeter=4+2*sqrt(3)
    Triangle tri2(2,0,3,sqrt(3),2,2*sqrt(3));//perimeter=4+2*sqrt(3)
    Rectangle rect(0,0,2,2*sqrt(3));//perimeter=4+4*sqrt(3)

    ShapeMedia s1(&tri1);
    ShapeMedia s2(&rect);
    vector<Media*> vm1{&s1,&s2};
    ComboMedia rh1(vm1);

    ShapeMedia s3(&tri2);
    vector<Media*> vm2{&s3,&rh1};
    ComboMedia rh2(vm2);

    PerimeterVisitor pv;
    rh2.accept(&pv);
    DOUBLES_EQUAL(12+8*sqrt(3),pv.getPerimeter(),epsilon);
}


#endif // UTSHAPES_H_INCLUDED
