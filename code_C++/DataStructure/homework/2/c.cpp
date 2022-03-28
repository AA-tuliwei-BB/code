/***********************************************************
  > File Name: c.cpp
  > Author: TALBW
  > Created Time: Tue 22 Mar 2022 04:26:37 PM CST
 *******************************************************/

#include <bits/stdc++.h>

using namespace std;

const int maxn = 5e3;

int input() {
	int x;
	scanf("%d", &x);
	return x;
}

int n;
int a[maxn + 5], b[maxn + 5];
int ls[maxn + 5], rs[maxn + 5], val[maxn + 5], tot;

int build(int *a, int *b, int n) {
	if (!n) return 0;
	int rt = ++tot;
	val[rt] = a[1];
	for (int i = 1; i <= n; ++i)
		if (b[i] == a[1]) {
			ls[rt] = build(a + 1, b, i - 1);
			rs[rt] = build(a + i, b + i, n - i);
			break;
		}
	return rt;
}

void dfs(int rt) {
	if (ls[rt]) dfs(ls[rt]);
	if (rs[rt]) dfs(rs[rt]);
	printf("%d ", val[rt]);
}

int main() {
	n = input();
	for (int i = 1; i <= n; ++i) a[i] = input();
	for (int i = 1; i <= n; ++i) b[i] = input();

	int root = build(a, b, n);

	dfs(root);
	puts("");
	return 0;
}
