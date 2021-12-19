#include <bits/stdc++.h>
#include "class.h"

using namespace std;

Complex operator + (Complex a, Complex b) {
	return Complex(a.r + b.r, a.i + b.i);
}

Complex operator - (Complex a, Complex b) {
	return Complex(a.r - b.r, a.i - b.i);
}

Complex operator * (Complex a, Complex b) {
	return Complex(a.r * b.r - a.i * b.i, a.i * b.r + a.r * b.i);
}

Complex operator / (Complex b, Complex a) {
	Complex res;
	float tmp = a.r * a.r + a.i * a.i;
	res.r = (a.r * b.r + a.i * b.i) / tmp;
	res.i = (a.r * b.i - a.i * b.r) / tmp;
	return res;
}

istream & operator >> (istream &in, Complex &a) {
	in >> a.r >> a.i;
	return in;
}

ostream & operator << (ostream &out, Complex a) {
	out << fixed << setprecision(2) << a.r << ' ' << a.i;
	return out;
}
