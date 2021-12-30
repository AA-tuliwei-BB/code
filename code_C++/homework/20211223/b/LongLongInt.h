/***********************************************************
  > File Name: LongLongInt.h
  > Author: TALBW
  > Created Time: Thu 23 Dec 2021 04:07:38 PM CST
 *******************************************************/

#ifndef LONGLONGINT
#define LONGLONGINT
#include <bits/stdc++.h>
using namespace std;
class LongLongInt {
	friend istream & operator >> (istream &in, LongLongInt &a);
	friend ostream & operator << (ostream &out, LongLongInt &a);
	friend LongLongInt operator + (LongLongInt a, LongLongInt b);
public:
	int len;
	int nu[100005];
    LongLongInt(const string&);
    LongLongInt();
    bool Zero() {
        for (int i = 0; i < len; ++i)
            if (nu[i]) return false;
        return true;
    }
};
#endif

