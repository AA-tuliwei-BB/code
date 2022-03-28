/***********************************************************
  > File Name: main.cpp
  > Author: TALBW
  > Created Time: Sat 26 Feb 2022 09:04:58 PM CST
 *******************************************************/

#include <bits/stdc++.h>
#include"MemoryRiver.hpp"

using namespace std;

MemoryRiver<double, 10> mr("a.dat");

int main() {
	mr.initialise();
	int tmp = 0;
	mr.get_info(tmp, 2);
	cout << tmp << endl;
	mr.write_info(4, 3);
	mr.get_info(tmp, 3);
	cout << tmp << endl;

	double a = 1.01, b = 2.02, c = 3.03;
	int ida = mr.write(a), idb = mr.write(b);
	cout << ida << ' ' << idb << endl;
	mr.read(a, idb), mr.read(b, ida);
	cout << a << ' ' << b << endl;
	mr.update(c, idb);
	mr.read(a, ida), mr.read(b, idb);
	cout << a << ' ' << b << endl;
	return 0;
}
