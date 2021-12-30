/***********************************************************
  > File Name: circle.h
  > Author: TALBW
  > Created Time: Thu 23 Dec 2021 02:27:47 PM CST
 *******************************************************/

#ifndef CIRCLE_H
#define CIRCLE_H

class Circle: public Shape {
public:
	int r;
	Circle();
	Circle(int, int, int);
	double area();
	double circum();
};

#endif
