/***********************************************************
  > File Name: rectangle.cpp
  > Author: TALBW
  > Created Time: Thu 23 Dec 2021 02:27:49 PM CST
 *******************************************************/

#include "rectangle.h"
#include "shape.h"

Rectangle::Rectangle() {}
Rectangle::Rectangle(int _x, int _y, int rw, int rh):
Shape(_x, _y) { w = rw, h = rh; }

double Rectangle::area() { return w * h; }
double Rectangle::circum() { return (w + h) << 1; }
