/***********************************************************
  > File Name: g.cpp
  > Author: TALBW
  > Created Time: Tue 22 Mar 2022 06:44:35 PM CST
 *******************************************************/

#include <iostream>
#include <cstdio>

int input() {
	int x; char ch;
	while (!isdigit(ch = getchar()));
	for (x = ch ^ 48; isdigit(ch = getchar()); x = x * 10 + (ch ^ 48));
	return x;
}

const int maxn = 1e6;

inline void chkmin(int &x, int y) { x = x < y ? x : y; }
inline void chkmax(int &x, int y) { x = x < y ? y : x; }

int n;
int h[maxn + 5];
int l[maxn + 5];
int stk[maxn + 5], pos[maxn + 5], top;

int main() {
	n = input();
	for (int i = 1; i <= n; ++i) h[i] = input();
	for (int i = 2; i <= n; ++i)
		for (int j = i - 1; j; j = l[j])
			if (h[j] > h[i]) {
				l[i] = j;
				break;
			}

	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		while (top and stk[top] >= h[i]) --top;
		stk[++top] = h[i], pos[top] = i;

		int L = 1, r = top, mid, res;
		while (L <= r) {
			mid = (L + r) >> 1;
			if (pos[mid] > l[i]) res = pos[mid], r = mid - 1;
			else L = mid + 1;
		}
		chkmax(ans, i - res + 1);
	}

	printf("%d\n", ans);
	return 0;
}
