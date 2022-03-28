/***********************************************************
  > File Name: e.cpp
  > Author: TALBW
  > Created Time: Tue 22 Mar 2022 06:11:59 PM CST
 *******************************************************/

#include <iostream>
#include <cstdio>

using namespace std;

const int maxn = 1e6, maxm = 2e3;

int input() {
	int x;
	scanf("%d", &x);
	return x;
}

void chkmin(int &x, int y) { x = x < y ? x : y; }

int n, m;
int a[maxn + 5];
int cnt[maxm + 5], tot;
int ansr = 0x3f3f3f3f, ansl = 0;

int main() {
	n = input(), m = input();
	for (int l = 1, r = 1; r <= n; ++r) {
		a[r] = input();
		if (!cnt[a[r]]) ++tot;
		++cnt[a[r]];
		while (cnt[a[l]] > 1) --cnt[a[l++]];
		if (tot == m and r - l + 1 < ansr - ansl + 1)
			ansr = r, ansl = l;
	}

	printf("%d %d\n", ansl, ansr);
	return 0;
}
