/***********************************************************
  > File Name: T6.cpp
  > Author: TALBW
  > Created Time: Thu 31 Mar 2022 05:46:18 PM CST
 *******************************************************/

#include <iostream>
#include <cstdio>

int input() {
	int x;
	scanf("%d", &x);
	return x;
}

const int maxn = 1e5, maxm = 2e5;

int head[maxn + 5], ne[maxm + 5], to[maxm + 5], val[maxm + 5], cnte;

void AddEdge(int x, int y) {
	ne[++cnte] = head[x], head[x] = cnte, to[cnte] = y;
	ne[++cnte] = head[y], head[y] = cnte, to[cnte] = x;
}

int n, m;
int f[maxn + 5][21], dep[maxn + 5];
int cnt[maxn + 5];

void dfs(int u, int fa) {
	f[u][0] = fa;
	dep[u] = dep[fa] + 1;
	for (int i = 1; i <= 20; ++i) {
		f[u][i] = f[f[u][i - 1]][i - 1];
		if (!f[u][i]) break;
	}
	for (int i = head[u]; i; i = ne[i]) {
		if (to[i] == fa) continue;
		dfs(to[i], u);
	}
}

int getLCA(int u, int v) {
	if (dep[u] > dep[v]) std::swap(u, v);
	int d = dep[v] - dep[u];
	for (int i = 20; ~i; --i)
		if (1 << i & d) v = f[v][i];
	if (u == v) return u;

	for (int i = 20; ~i; --i)
		if (f[u][i] != f[v][i])
			u = f[u][i], v = f[v][i];
	return f[u][0];
}

void getSum(int u, int fa) {
	for (int i = head[u]; i; i = ne[i]) {
		if (to[i] == fa) continue;
		getSum(to[i], u);
		cnt[u] += cnt[to[i]];
	}
}

int main() {
	n = input(), m = input();
	for (int i = 1; i < n; ++i) {
		int u = input(), v = input(), w = input();
		AddEdge(u, v);
	}

	dfs(1, 0);
	while (m--) {
		int x = input(), y = input(), lca = getLCA(x, y);
		++cnt[x], ++cnt[y], --cnt[lca], --cnt[f[lca][0]];
	}
	getSum(1, 0);

	int ans = 0;
	for (int i = 1; i <= n; ++i)
		ans = ans > cnt[i] ? ans : cnt[i];
	printf("%d\n", ans);
	return 0;
}
