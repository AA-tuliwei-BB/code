/***********************************************************
  > File Name: square.cpp
  > Author: TALBW
  > Created Time: Thu 23 Dec 2021 02:27:53 PM CST
 *******************************************************/

#include "square.h"
#include "rectangle.h"

Square::Square() {}
Square::Square(int _x, int _y, int l) : Rectangle(_x, _y, l, l) {}
