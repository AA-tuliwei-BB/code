#include <bits/stdc++.h>
#include "module1.h"
#include "module2.h"

using namespace std;

/*
	实现功能:
	MaxInterestA() : 买一次最大利润
	MaxInterestB() : 买任意次最大利润
*/

void MaxInterestA() {
	int Min = 0x3f3f3f3f, res = 0;
	for (int pri : p) {
		if (pri < Min) Min = pri;
		else res = max(res, pri - Min);
	}
	cout << res << endl;
}

void MaxInterestB() {
	int res = 0;
	for (int i = 1; i < p.size(); ++i)
		if (p[i] > p[i - 1]) res += p[i] - p[i - 1];
	cout << res << endl;
}
