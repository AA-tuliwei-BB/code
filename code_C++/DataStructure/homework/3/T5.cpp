/***********************************************************
  > File Name: T5.cpp
  > Author: TALBW
  > Created Time: Thu 31 Mar 2022 05:10:18 PM CST
 *******************************************************/

#include <iostream>
#include <cstdio>

int input() {
	int x;
	scanf("%d", &x);
	return x;
}

const int maxn = 5e4, maxm = 1e5;

int head[maxn + 5], ne[maxm + 5], to[maxm + 5], val[maxm + 5], cnt;

void AddEdge(int x, int y, int v) {
	ne[++cnt] = head[x], head[x] = cnt, to[cnt] = y, val[cnt] = v;
	ne[++cnt] = head[y], head[y] = cnt, to[cnt] = x, val[cnt] = v;
}

int n, m;
int f[maxn + 5][21], dep[maxn + 5];
int sum[maxn + 5][21];

void dfs(int u, int fa) {
	f[u][0] = fa;
	dep[u] = dep[fa] + 1;
	for (int i = 1; i <= 20; ++i) {
		f[u][i] = f[f[u][i - 1]][i - 1];
		if (!f[u][i]) break;
		sum[u][i] = sum[f[u][i - 1]][i - 1] + sum[u][i - 1];
	}
	for (int i = head[u]; i; i = ne[i]) {
		if (to[i] == fa) continue;
		sum[to[i]][0] = val[i];
		dfs(to[i], u);
	}
}

int getSum(int u, int v) {
	int res = 0;
	if (dep[u] > dep[v]) std::swap(u, v);
	int d = dep[v] - dep[u];
	for (int i = 20; ~i; --i)
		if (1 << i & d) res += sum[v][i], v = f[v][i];

	if (u == v) return res;
	for (int i = 20; ~i; --i)
		if (f[u][i] != f[v][i]) {
			res += sum[u][i] + sum[v][i];
			u = f[u][i], v = f[v][i];
		}
	res += sum[u][0] + sum[v][0];
	return res;
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

int getAns(int x, int y, int z) {
	int lxy = getLCA(x, y), res = getSum(x, y);
	int lxyz = getLCA(lxy, z);
	if (lxyz != lxy) return res + getSum(lxy, z);
	int lxz = getLCA(x, z);
	if (lxz == z) return res;
	if (dep[lxz] > dep[lxyz]) return res + getSum(lxz, z);
	int lyz = getLCA(y, z);
	if (lyz == z) return res;
	if (dep[lyz] > dep[lxyz]) return res + getSum(lyz, z);
	return res + getSum(z, lxy);
}

int main() {
	n = input();
	for (int i = 1; i < n; ++i) {
		int u = input(), v = input(), w = input();
		AddEdge(u, v, w);
	}

	dfs(1, 0);

	m = input();
	while (m--) printf("%d\n", getAns(input(), input(), input()));
	return 0;
}
