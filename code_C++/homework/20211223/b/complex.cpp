/***********************************************************
  > File Name: complex.cpp
  > Author: TALBW
  > Created Time: Thu 23 Dec 2021 04:08:01 PM CST
 *******************************************************/

#include <bits/stdc++.h>
#include "LLIComplex.h"
#include "LongLongInt.h"

using namespace std;

longlongintcomplex operator + (longlongintcomplex a, longlongintcomplex b) {
	return longlongintcomplex(a.r + b.r, a.i + b.i);
}

istream & operator >> (istream &in, longlongintcomplex &a) {
	in >> a.r >> a.i;
	return in;
}

ostream & operator << (ostream &out, longlongintcomplex a) {
	if (!a.r.Zero() or a.i.Zero()) {
		if (!a.r.Zero()) out << a.r;
		else out << "0i";
        if (!a.i.Zero()) out << '+' << a.i << 'i';
    } else out << a.i << 'i';
	return out;
}

