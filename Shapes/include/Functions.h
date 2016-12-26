#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <vector>
#include <iostream>
#include <algorithm>

#include "Shapes.h"
#include "Geometry.h"

using namespace std;

double sumOfPerimeter(vector<Shape*> shapes);
double sumOfArea(vector<Shape*> shapes);
vector<Shape*>& maxArea(vector<Shape*> shapes);
bool isLarger(const Shape* x,const Shape* y);
void sortByDecreasingPerimeter(vector<Shape*> &shapes);
void runGeometry();

#endif // FUNCTIONS_H
