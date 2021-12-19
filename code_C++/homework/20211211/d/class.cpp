#include <bits/stdc++.h>
#include "class.h"
using namespace std;

istream & operator >> (istream &in, BigInteger &a) {
	string tmp; in >> tmp;
	for (int i = 0, n = tmp.size(); i < n; ++i)
		a.nu[n - i - 1] = tmp[i] - '0';
	a.len = tmp.size();
	return in;
}

ostream & operator << (ostream &out, BigInteger &a) {
	for (int i = a.len - 1; ~i; --i)
		out << a.nu[i];
	return out;
}

BigInteger & operator + (BigInteger &a, BigInteger &b) {
	int flag = 0;
	static BigInteger c;
	BigInteger &Len = a.len > b.len ? a : b;
	for (int i = 0, n = std::min(a.len, b.len); i < n; ++i) {
		int tmp = a.nu[i] + b.nu[i] + flag;
		if (tmp >= 10) flag = 1, c.nu[i] = tmp - 10;
		else flag = 0, c.nu[i] = tmp;
	}
	for (int i = std::min(a.len, b.len); i < Len.len; ++i) {
		int tmp = Len.nu[i] + flag;
		if (tmp >= 10) c.nu[i] = tmp - 10, flag = 1;
		else c.nu[i] = tmp;
	}
	c.len = Len.len;
	if (flag) c.nu[c.len++] = 1;
	return c;
}
