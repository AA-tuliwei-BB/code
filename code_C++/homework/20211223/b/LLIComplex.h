/***********************************************************
  > File Name: LLIComplex.h
  > Author: TALBW
  > Created Time: Thu 23 Dec 2021 04:08:18 PM CST
 *******************************************************/

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
    longlongintcomplex (LongLongInt a, LongLongInt b) { r = a, i = b; }
	longlongintcomplex (const string& a, const string& b) { r = LongLongInt(a), i = LongLongInt(b); }
	friend longlongintcomplex operator + (longlongintcomplex a, longlongintcomplex b);
	friend istream & operator >> (istream &in, longlongintcomplex &a);
	friend ostream & operator << (ostream &out, longlongintcomplex a);
};

#endif 

