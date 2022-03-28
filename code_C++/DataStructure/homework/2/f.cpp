/***********************************************************
  > File Name: f.cpp
  > Author: TALBW
  > Created Time: Tue 22 Mar 2022 06:24:28 PM CST
 *******************************************************/

#include <iostream>
#include <cstdio>

int input() {
	int x; char ch;
	while (!isdigit(ch = getchar()));
	for (x = ch ^ 48; isdigit(ch = getchar()); x = x * 10 + (ch ^ 48));
	return x;
}

const int maxn = 1e3;

inline void chkmin(int &x, int y) { x = x < y ? x : y; }
inline void chkmax(int &x, int y) { x = x < y ? y : x; }

int n, m, t;
int a[maxn + 5][maxn + 5];
int max[maxn + 5][maxn + 5], min[maxn + 5][maxn + 5];

int main() {
	n = input(), m = input(), t = input();
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			a[i][j] = input();

	for (int i = 1; i + t - 1 <= n; ++i)
		for (int j = 1; j + t - 1 <= m; ++j) {
			max[i][j] = min[i][j] = a[i][j];
			for (int k = j + 1; k < j + t; ++k) {
				chkmin(min[i][j], a[i][k]);
				chkmax(max[i][j], a[i][k]);
			}
		}

	int ans = 0x3f3f3f3f;
	for (int i = 1; i + t - 1 <= n; ++i)
		for (int j = 1; j + t - 1 <= m; ++j) {
			for (int k = i + 1; k < i + t; ++k) {
				chkmin(min[i][j], min[k][j]);
				chkmax(max[i][j], max[k][j]);
			}
			chkmin(ans, max[i][j] - min[i][j]);
		}
	printf("%d\n", ans);
	return 0;
}
