#ifndef CLASS_H
#define CLASS_H

#include <bits/stdc++.h>
#include "LongLongInt.h"
using namespace std;

class longlongintcomplex {
private:
	LongLongInt r, i;
public:
    longlongintcomplex () {}
	longlongintcomplex (const string& a, const string& b) { r = LongLongInt(a), i = LongLongInt(b); }
	friend longlongintcomplex operator + (longlongintcomplex a, longlongintcomplex b);
	friend longlongintcomplex operator - (longlongintcomplex a, longlongintcomplex b);
	friend istream & operator >> (istream &in, longlongintcomplex &a);
	friend ostream & operator << (ostream &out, longlongintcomplex a);
};

#endif 
