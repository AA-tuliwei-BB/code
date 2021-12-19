#ifndef CLASS_H
#define CLASS_H

#include <iostream>
using namespace std;

class Complex {
private:
	float r, i;
public:
	Complex (float a = 0, float b = 0) { r = a, i = b; }
	friend Complex operator + (Complex a, Complex b);
	friend Complex operator - (Complex a, Complex b);
	friend Complex operator * (Complex a, Complex b);
	friend Complex operator / (Complex a, Complex b);
	friend istream & operator >> (istream &in, Complex &a);
	friend ostream & operator << (ostream &out, Complex a);
};

#endif 
