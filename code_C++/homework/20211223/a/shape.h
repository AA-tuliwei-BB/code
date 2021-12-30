/***********************************************************
  > File Name: shape.h
  > Author: TALBW
  > Created Time: Thu 23 Dec 2021 02:27:58 PM CST
 *******************************************************/

#ifndef SHAPE_H
#define SHAPE_H

class Shape {
public:
	int x, y;
	Shape();
	Shape(int, int);
	void show_position();
	virtual double area();
	virtual double circum();
};

#endif
