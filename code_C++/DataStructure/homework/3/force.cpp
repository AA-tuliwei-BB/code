/***********************************************************
  > File Name: force.cpp
  > Author: TALBW
  > Created Time: Thu 31 Mar 2022 08:40:13 PM CST
 *******************************************************/

#include <iostream>
#include <cstdio>

using namespace std;

int input() {
	int x;
	scanf("%d", &x);
	return x;
}

const int maxn = 5e5, maxm = 1e6, maxbit = 11;

int head[maxn + 5], ne[maxm + 5], to[maxm + 5], val[maxm + 5], cnte;

void AddEdge(int x, int y, int v) {
	ne[++cnte] = head[x], head[x] = cnte, to[cnte] = y, val[cnte] = v;
	ne[++cnte] = head[y], head[y] = cnte, to[cnte] = x, val[cnte] = v;
}

int n, m;
int toroot[maxn + 5];
int v_all;

void dfs(int u, int fa) {
	for (int i = head[u]; i; i = ne[i]) {
		if (to[i] == fa) continue;
		toroot[to[i]] = toroot[u] ^ val[i];
		dfs(to[i], u);
	}
}

inline void chkmax(int &x, int y) { x = x < y ? y : x; }

int main() {
	n = input(), m = input();
	for (int i = 1; i < n; ++i) {
		int u = input(), v = input(), w = input();
		AddEdge(u, v, w);
	}

	dfs(1, 0);

	while (m--) {
		int opt = input();
		if (opt == 2) {
			int v = input();
			for (int i = 1; i <= cnte; ++i)
				val[i] ^= v;
			dfs(1, 0);
		} else {
			int x = input(), y = input(), res = 0;
			for (int i = 1; i <= n; ++i)
				for (int j = 1; j <= n; ++j) {
					int dx = toroot[x] ^ toroot[i];
					int dy = toroot[y] ^ toroot[j];
					chkmax(res, dx ^ dy);
				}
			printf("%d\n", res);
		}
	}
	return 0;
}
