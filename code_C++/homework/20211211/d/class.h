#ifndef CLASS_H
#define CLASS_H
#include <iostream>
using namespace std;
class BigInteger {
	friend istream & operator >> (istream &in, BigInteger &a);
	friend ostream & operator << (ostream &out, BigInteger &a);
	friend BigInteger & operator + (BigInteger &a, BigInteger &b);
public:
	int len;
	int nu[1005];
};
#endif
