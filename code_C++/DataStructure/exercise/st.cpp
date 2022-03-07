/***********************************************************
  > File Name: st.cpp
  > Author: TALBW
  > Created Time: Sun 27 Feb 2022 06:33:25 PM CST
 *******************************************************/

#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5, maxm = 2e6;

int n, m;
int a[maxn + 5];
int st[maxn + 5][21];
int lg[maxn + 5];

int input() {
	int x;
	scanf("%d", &x);
	return x;
}

void build() {
	for (int i = 2; i <= n; ++i)
		lg[i] = lg[i >> 1] + 1;
	for (int i = 1; i <= n; ++i) st[i][0] = a[i];

	for (int j = 0; j < lg[n]; ++j)
		for (int i = 1; i <= n; ++i)
			if (i + (1 << j) > n) st[i][j + 1] = st[i][j];
			else st[i][j + 1] = max(st[i][j], st[i + (1 << j)][j]);
}

int query(int l, int r) {
	int Log = lg[r - l];
	return max(st[l][Log], st[r - (1 << Log) + 1][Log]);
}

int main() {
	n = input(), m = input();
	for (int i = 1; i <= n; ++i)
		a[i] = input();

	build();

	while (m--) {
		int l = input(), r = input();
		printf("%d\n", query(l, r));
	}
	return 0;
}
