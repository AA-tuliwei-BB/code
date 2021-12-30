/***********************************************************
  > File Name: rectangle.h
  > Author: TALBW
  > Created Time: Thu 23 Dec 2021 02:27:50 PM CST
 *******************************************************/

#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "shape.h"

class Rectangle: public Shape {
public:
	int w, h;
	Rectangle();
	Rectangle(int, int, int, int);
	double area();
	double circum();
};

#endif
