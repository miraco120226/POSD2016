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
#include "DescriptionVisitor.h"
#include "MediaBuilder.h"
#include "ShapeMediaBuilder.h"
#include "ComboMediaBuilder.h"
#include "TextMedia.h"

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

TEST (DescriptionVisitor, ShapeMedia) {
    Triangle tri(0,0,3,0,0,4);
    ShapeMedia s1(&tri);

    DescriptionVisitor dv;
    s1.accept(&dv);
    CHECK(string("t(0 0 3 0 0 4) ")==dv.getDescription());
}

TEST (DescriptionVisitor, ComboMedia) {
    Triangle tri(0,0,3,0,0,4);
    Circle circ(0,0,2);
    Rectangle rect(0,0,2,3);
    ShapeMedia s1(&tri);
    ShapeMedia s2(&circ);
    ShapeMedia s3(&rect);
    vector<Media*> vm{&s1,&s2,&s3};
    ComboMedia cm(vm);

    DescriptionVisitor dv;
    cm.accept(&dv);
    CHECK(string("combo(t(0 0 3 0 0 4) c(0 0 2) r(0 0 2 3) )")==dv.getDescription());
}

TEST (Circle, ShapeMediaBuilder) {
    Circle circ(0,0,5);

    ShapeMediaBuilder smb;
    smb.buildShapeMedia(&circ);

    ShapeMedia* sm=(ShapeMedia*)smb.getMedia();

    DescriptionVisitor dv;
    sm->accept(&dv);
    CHECK(string("c(0 0 5) ")==dv.getDescription());
}

TEST (house, ComboMediaBuilder) {

    Rectangle rec1(10,0,15,5);
    Circle circ(12,5,2);

    ShapeMediaBuilder smb;
    smb.buildShapeMedia(&rec1);
    ShapeMediaBuilder smb2;
    smb2.buildShapeMedia(&circ);

    ComboMediaBuilder cmb;
    cmb.buildComboMedia();
    cmb.buildAddShapeMedia((ShapeMedia*)smb.getMedia());
    cmb.buildAddShapeMedia((ShapeMedia*)smb2.getMedia());


    ComboMedia* cm=(ComboMedia*)cmb.getMedia();
    Rectangle rec2(0,0,25,20);

    ShapeMediaBuilder smb3;
    smb3.buildShapeMedia(&rec2);

    ComboMediaBuilder cmb2;
    cmb2.buildComboMedia();
    cmb2.buildAddComboMedia(cm);
    cmb2.buildAddShapeMedia((ShapeMedia*)smb3.getMedia());


    ComboMedia* cm2=(ComboMedia*)cmb2.getMedia();
    Triangle tri(0,20,16,32,25,20);

    ShapeMediaBuilder smb4;
    smb4.buildShapeMedia(&tri);

    ComboMediaBuilder cmb3;
    cmb3.buildComboMedia();
    cmb3.buildAddComboMedia(cm2);
    cmb3.buildAddShapeMedia((ShapeMedia*)smb4.getMedia());

    DescriptionVisitor dv;
    cmb3.getMedia()->accept(&dv);

    CHECK(string("combo(combo(combo(r(10 0 15 5) c(12 5 2) )r(0 0 25 20) )t(0 20 16 32 25 20) )")==dv.getDescription());
}

#include<stack>
TEST (house_stack, ComboMediaBuilder) {
    stack<ComboMediaBuilder *> mbs;
    mbs.push(new ComboMediaBuilder());
    mbs.top()->buildComboMedia();
    mbs.push(new ComboMediaBuilder());
    mbs.top()->buildComboMedia();
    mbs.push(new ComboMediaBuilder());
    mbs.top()->buildComboMedia();

    Rectangle rec1(10,0,15,5);
    ShapeMediaBuilder smb;
    smb.buildShapeMedia(&rec1);
    mbs.top()->buildAddShapeMedia((ShapeMedia*)smb.getMedia());

    Circle circ(12,5,2);
    ShapeMediaBuilder smb2;
    smb2.buildShapeMedia(&circ);
    mbs.top()->buildAddShapeMedia((ShapeMedia*)smb2.getMedia());

    ComboMedia* cm1=(ComboMedia*)mbs.top()->getMedia();
    mbs.pop();
    mbs.top()->buildAddComboMedia(cm1);

    Rectangle rec2(0,0,25,20);
    ShapeMediaBuilder smb3;
    smb3.buildShapeMedia(&rec2);
    mbs.top()->buildAddShapeMedia((ShapeMedia*)smb3.getMedia());

    ComboMedia* cm2=(ComboMedia*)mbs.top()->getMedia();
    mbs.pop();
    mbs.top()->buildAddComboMedia(cm2);

    Triangle tri(0,20,16,32,25,20);
    ShapeMediaBuilder smb4;
    smb4.buildShapeMedia(&tri);
    mbs.top()->buildAddShapeMedia((ShapeMedia*)smb4.getMedia());

    ComboMedia* cm3=(ComboMedia*)mbs.top()->getMedia();
    mbs.pop();

    DescriptionVisitor dv;
    cm3->accept(&dv);

    CHECK(string("combo(combo(combo(r(10 0 15 5) c(12 5 2) )r(0 0 25 20) )t(0 20 16 32 25 20) )")==dv.getDescription());
}

TEST (TextMedia1, TextMedia) {
    Rectangle rec(0,0,10,10);
    string text("Test");
    Text txt(rec,text);
    TextMedia tm(&txt);

    DOUBLES_EQUAL(100,tm.area(),epsilon);
}

TEST (TextMedia2, TextMedia) {
    Rectangle rec(0,0,10,10);
    string text("Test");
    Text txt(rec,text);
    TextMedia tm(&txt);

    DOUBLES_EQUAL(40,tm.perimeter(),epsilon);
}

TEST (TextMedia3, TextMedia) {
    Rectangle rec(0,0,10,10);
    string text("Test");
    Text txt(rec,text);
    TextMedia tm(&txt);

    CHECK(string("Test")==tm.getText()->getText())
}

TEST (removeShapeMedia, removeMedia) {
    Rectangle rec1(10,0,15,5);
    Circle circ(12,5,2);

    ShapeMediaBuilder smb;
    smb.buildShapeMedia(&rec1);
    ShapeMediaBuilder smb2;
    smb2.buildShapeMedia(&circ);

    ComboMediaBuilder cmb;
    cmb.buildComboMedia();
    cmb.buildAddShapeMedia((ShapeMedia*)smb.getMedia());
    cmb.buildAddShapeMedia((ShapeMedia*)smb2.getMedia());


    ComboMedia* cm=(ComboMedia*)cmb.getMedia();
    Rectangle rec2(0,0,25,20);

    ShapeMediaBuilder smb3;
    smb3.buildShapeMedia(&rec2);

    ComboMediaBuilder cmb2;
    cmb2.buildComboMedia();
    cmb2.buildAddComboMedia(cm);
    cmb2.buildAddShapeMedia((ShapeMedia*)smb3.getMedia());


    ComboMedia* cm2=(ComboMedia*)cmb2.getMedia();
    Triangle tri(0,20,16,32,25,20);

    ShapeMediaBuilder smb4;
    smb4.buildShapeMedia(&tri);

    ComboMediaBuilder cmb3;
    cmb3.buildComboMedia();
    cmb3.buildAddComboMedia(cm2);
    cmb3.buildAddShapeMedia((ShapeMedia*)smb4.getMedia());

    Rectangle rec3(0,0,25,20);
    ShapeMediaBuilder smb5;
    smb5.buildShapeMedia(&rec3);

    ((ComboMedia*)cmb3.getMedia())->removeMedia(smb5.getMedia());

    DescriptionVisitor dv;
    ((ComboMedia*)cmb3.getMedia())->accept(&dv);

    CHECK(string("combo(combo(combo(r(10 0 15 5) c(12 5 2) ))t(0 20 16 32 25 20) )")==dv.getDescription());
}

TEST (removeComboMedia, removeMedia) {
    Rectangle rec1(10,0,15,5);
    Circle circ(12,5,2);

    ShapeMediaBuilder smb;
    smb.buildShapeMedia(&rec1);
    ShapeMediaBuilder smb2;
    smb2.buildShapeMedia(&circ);

    ComboMediaBuilder cmb;
    cmb.buildComboMedia();
    cmb.buildAddShapeMedia((ShapeMedia*)smb.getMedia());
    cmb.buildAddShapeMedia((ShapeMedia*)smb2.getMedia());


    ComboMedia* cm=(ComboMedia*)cmb.getMedia();
    Rectangle rec2(0,0,25,20);

    ShapeMediaBuilder smb3;
    smb3.buildShapeMedia(&rec2);

    ComboMediaBuilder cmb2;
    cmb2.buildComboMedia();
    cmb2.buildAddComboMedia(cm);
    cmb2.buildAddShapeMedia((ShapeMedia*)smb3.getMedia());


    ComboMedia* cm2=(ComboMedia*)cmb2.getMedia();
    Triangle tri(0,20,16,32,25,20);

    ShapeMediaBuilder smb4;
    smb4.buildShapeMedia(&tri);

    ComboMediaBuilder cmb3;
    cmb3.buildComboMedia();
    cmb3.buildAddComboMedia(cm2);
    cmb3.buildAddShapeMedia((ShapeMedia*)smb4.getMedia());

    Rectangle rec3(0,0,25,20);
    ShapeMediaBuilder smb5;
    smb5.buildShapeMedia(&rec3);

    ((ComboMedia*)cmb3.getMedia())->removeMedia(cm);

    DescriptionVisitor dv;
    ((ComboMedia*)cmb3.getMedia())->accept(&dv);

    CHECK(string("combo(combo(r(0 0 25 20) )t(0 20 16 32 25 20) )")==dv.getDescription());
}

#endif // UTSHAPES_H_INCLUDED
