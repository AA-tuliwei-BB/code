/***********************************************************
  > File Name: long.cpp
  > Author: TALBW
  > Created Time: Thu 23 Dec 2021 04:07:28 PM CST
 *******************************************************/

#include <bits/stdc++.h>
#include "LongLongInt.h"
using namespace std;

LongLongInt::LongLongInt() {}

LongLongInt::LongLongInt(const string& tmp) {
	for (int i = 0, n = tmp.size(); i < n; ++i)
		this->nu[n - i - 1] = tmp[i] - '0';
	this->len = tmp.size();
}

istream & operator >> (istream &in, LongLongInt &a) {
	string tmp; in >> tmp;
	for (int i = 0, n = tmp.size(); i < n; ++i)
		a.nu[n - i - 1] = tmp[i] - '0';
	a.len = tmp.size();
	return in;
}

ostream & operator << (ostream &out, LongLongInt &a) {
	int flag = 1;
	for (int i = a.len - 1; ~i; --i) {
		if (a.nu[i]) flag = 0;
		else if (flag) continue;
		out << a.nu[i];
	}
	if (flag) out << '0';
	return out;
}

LongLongInt operator + (LongLongInt a, LongLongInt b) {
	int flag = 0;
	LongLongInt c;
	LongLongInt Len = a.len > b.len ? a : b;
	for (int i = 0, n = std::min(a.len, b.len); i < n; ++i) {
		int tmp = a.nu[i] + b.nu[i] + flag;
		if (tmp >= 10) flag = 1, c.nu[i] = tmp - 10;
		else flag = 0, c.nu[i] = tmp;
	}
	for (int i = std::min(a.len, b.len); i < Len.len; ++i) {
		int tmp = Len.nu[i] + flag;
		if (tmp >= 10) c.nu[i] = tmp - 10, flag = 1;
		else c.nu[i] = tmp, flag = 0;
	}
	c.len = Len.len;
	if (flag) c.nu[c.len++] = 1;
	return c;
}
