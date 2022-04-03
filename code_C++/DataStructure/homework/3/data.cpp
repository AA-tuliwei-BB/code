/***********************************************************
  > File Name: data.cpp
  > Author: TALBW
  > Created Time: Thu 31 Mar 2022 08:34:21 PM CST
 *******************************************************/

#include <bits/stdc++.h>

using namespace std;

const int n = 40, m = 40, Max = (1 << 12) - 1;

int Rand(int x) { return rand() % x + 1; }
int Rand(int l, int r) { return rand() % (r - l + 1) + l; }

int main() {
	srand(time(0));
	freopen("test.in", "w", stdout);
	printf("%d %d\n", n, m);
	for (int i = 2; i <= n; ++i)
		printf("%d %d %d\n", i, Rand(i - 1), Rand(0, Max));
	for (int i = 1; i <= m; ++i) {
		int opt = Rand(2);
		printf("%d ", opt);
		if (opt == 1)
			printf("%d %d\n", Rand(n), Rand(n));
		else printf("%d\n", Rand(0, Max));
	}
}
