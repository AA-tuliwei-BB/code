/***********************************************************
  > File Name: shape.cpp
  > Author: TALBW
  > Created Time: Thu 23 Dec 2021 02:27:56 PM CST
 *******************************************************/

#include <bits/stdc++.h>
#include "shape.h"

Shape::Shape() {}
Shape::Shape(int _x, int _y) { x = _x, y = _y; }
void Shape::show_position() { printf("(%d,%d)", x, y); }
double Shape::area() { return 0; }
double Shape::circum() { return 0; }
