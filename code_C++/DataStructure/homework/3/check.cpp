/***********************************************************
  > File Name: check.cpp
  > Author: TALBW
  > Created Time: Thu 31 Mar 2022 08:48:07 PM CST
 *******************************************************/

#include <bits/stdc++.h>

using namespace std;

int main() {
	while (true) {
		system("./data");
		system("./xx < test.in > out");
		system("./force < test.in > ans");
		if (system("diff out ans")) break;
		else puts("AC");
	}
}
