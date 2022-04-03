/***********************************************************
  > File Name: T7.cpp
  > Author: TALBW
  > Created Time: Thu 31 Mar 2022 06:29:45 PM CST
 *******************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>

int input() {
	int x;
	scanf("%d", &x);
	return x;
}

const int maxn = 1e6, maxm = 1e6, maxdep = 14;

int head[maxn + 5], ne[maxm + 5], to[maxm + 5], cnte;
char val[maxm + 5];

void AddEdge(int x, int y, char v) {
	ne[++cnte] = head[x], head[x] = cnte, to[cnte] = y, val[cnte] = v;
}

int n, m;
int f[maxn + 5][maxdep + 1], dep[maxn + 5], cntn = 1;
int node[maxn + 5], cntnode;
char str[10005];

int AddNode(int fa, char val) {
	int now = ++cntn;
	AddEdge(fa, now, val);
	f[now][0] = fa, dep[now] = dep[fa] + 1;
	for (int i = 1; i <= maxdep; ++i) {
		f[now][i] = f[f[now][i - 1]][i - 1];
		if (!f[now][i]) break;
	}
	return now;
}

void AddString(int u, char *s) {
	if (!*s) return node[++cntnode] = u, void();
	for (int i = head[u]; i; i = ne[i])
		if (val[i] == *s) return AddString(to[i], s + 1);
	AddString(AddNode(u, *s), s + 1);
}

void AddString(char *s) {
	AddString(1, s);
}

int getLCA(int u, int v) {
	if (dep[u] > dep[v]) std::swap(u, v);
	int d = dep[v] - dep[u];
	for (int i = maxdep; ~i; --i)
		if (1 << i & d) v = f[v][i];
	if (u == v) return u;

	for (int i = maxdep; ~i; --i)
		if (f[u][i] != f[v][i])
			u = f[u][i], v = f[v][i];
	return f[u][0];
}

void reverse(char *s) {
	int len = strlen(s);
	for (int i = 0; i < len >> 1; ++i)
		std::swap(s[i], s[len - 1 - i]);
}

int main() {
	n = input(), m = input();
	for (int i = 1; i <= n; ++i) {
		scanf("%s", str);
		reverse(str);
		AddString(str);
	}

	while (m--) {
		int opt = input();
		if (opt == 1) {
			scanf("%s", str);
			reverse(str);
			AddString(str);
		}
		if (opt == 2) {
			int T = input(), A[11];
			for (int i = 1; i <= T; ++i)
				A[i] = input();
			int lca = node[A[1]];
			for (int i = 1; i <= T; ++i)
				lca = getLCA(lca, node[A[i]]);
			printf("%d\n", dep[lca]);
		}
	}

	return 0;
}
