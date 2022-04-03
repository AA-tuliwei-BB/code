/***********************************************************
  > File Name: a.cpp
  > Author: TALBW
  > Created Time: Sun 20 Mar 2022 06:33:25 PM CST
 *******************************************************/

#include <iostream>
#include <cstdio>

using namespace std;

int input() {
	int x;
	scanf("%d", &x);
	return x;
}

const int maxn = 1e4;

int n, m;
int a[maxn + 5], b[maxn + 5];
int stk[maxn + 5], top;

int main() {
	n = input();
	for (int i = 1; i <= n; ++i)
		a[i] = input();
	m = input();
	for (int i = 1; i <= m; ++i)
		b[i] = input();

	int now = 1;
	for (int i = 1; i <= n; ++i) {
		if (stk[top] >= a[i]) return puts("no"), 0;
		stk[++top] = a[i];
		while (stk[top] == b[now] and now <= m and top)
			--top, ++now;
	}
	puts("yes");
	return 0;
}
