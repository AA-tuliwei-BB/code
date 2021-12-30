/***********************************************************
  > File Name: circle.cpp
  > Author: TALBW
  > Created Time: Thu 23 Dec 2021 02:27:42 PM CST
 *******************************************************/

#include "shape.h"
#include "circle.h"

Circle::Circle() {}
Circle::Circle(int _x, int _y, int _r): Shape(_x, _y) { r = _r; }
double Circle::area() { return 3.1415926 * r * r; }
double Circle::circum() { return 3.1415926 * 2 * r; }
