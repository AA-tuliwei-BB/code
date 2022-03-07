/***********************************************************
  > File Name: T3.cpp
  > Author: TALBW
  > Created Time: Tue 01 Mar 2022 04:03:17 PM CST
 *******************************************************/

#include <iostream>

using namespace std;

int input() {
	int x;
	scanf("%d", &x);
	return x;
}

const int maxn = 1e5;

int n, m;
int l[maxn + 5], r[maxn + 5];
bool out[maxn + 5];

int main() {
	r[0] = 1;
	n = input();
	for (int i = 2; i <= n; ++i) {
		int x = input(), p = input();
		if (p == 0) {
			r[l[x]] = i, l[i] = l[x];
			l[x] = i, r[i] = x;
		} else {
			l[r[x]] = i, r[i] = r[x];
			r[x] = i, l[i] = x;
		}
	}

	m = input();
	while (m--) {
		int x = input();
		if (out[x]) continue;
		out[x] = true;
		r[l[x]] = r[x];
		l[r[x]] = l[x];
	}

	for (int i = r[0]; i; i = r[i]) printf("%d ", i);
	putchar('\n');
	return 0;
}
