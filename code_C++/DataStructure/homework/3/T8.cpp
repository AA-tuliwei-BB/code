/***********************************************************
  > File Name: T8.cpp
  > Author: TALBW
  > Created Time: Thu 31 Mar 2022 07:25:01 PM CST
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

// {{{ trie
struct Trie {
	int ch[(1 << (maxbit + 1)) + 5][2], cnt = 1, root = 1;

	void insert(int &rt, int x, int bit) {
		if (!rt) rt = ++cnt;
		if (bit == -1) return void();
		if (1 << bit & x) insert(ch[rt][1], x, bit - 1);
		else insert(ch[rt][0], x, bit - 1);
	}

	void insert(int x) { insert(root, x, maxbit); }

	int query(int rt, int x, int bit) {
		if (bit == -1) return 0;
		if (x & 1 << bit) {
			if (ch[rt][0]) return query(ch[rt][0], x, bit - 1) | 1 << bit;
			else return query(ch[rt][1], x, bit - 1);
		} else {
			if (ch[rt][1]) return query(ch[rt][1], x, bit - 1) | 1 << bit;
			else return  query(ch[rt][0], x, bit - 1);
		}
		exit(1);
	}

	int query(int x) { return query(root, x, maxbit); }
} trie[2];
// }}}

int n, m;
int toroot[maxn + 5], dep[maxn + 5];
int vis[2][1 << 12], vis2[2][1 << 12];
int v_all;

void dfs(int u, int fa) {
	dep[u] = dep[fa] + 1;
	for (int i = head[u]; i; i = ne[i]) {
		if (to[i] == fa) continue;
		toroot[to[i]] = toroot[u] ^ val[i];
		dfs(to[i], u);
	}
}

inline void chkmax(int &x, int y) { x = x < y ? y : x; }

int query(int x, int y) {
	int b = (dep[x] & 1) ^ (dep[y] & 1);
	int resa = trie[b].query(toroot[x] ^ toroot[y]);
	int resb = trie[b ^ 1].query(toroot[x] ^ toroot[y] ^ v_all);
	return std::max(resa, resb);
}

int main() {
	n = input(), m = input();
	for (int i = 1; i < n; ++i) {
		int u = input(), v = input(), w = input();
		AddEdge(u, v, w);
	}

	dfs(1, 0);

	for (int i = 1; i <= n; ++i)
		vis[dep[i] & 1][toroot[i]] = 1;

	for (int a = 0; a <= 1; ++a)
		for (int i = 0; i < 1 << 12; ++i)
			for (int b = 0; b <= 1; ++b)
				for (int j = 0; j < 1 << 12; ++j)
					vis2[a ^ b][i ^ j] |= vis[a][i] & vis[b][j];

	for (int a = 0; a <= 1; ++a)
		for (int i = 0; i < 1 << 12; ++i)
			if (vis2[a][i]) trie[a].insert(i);

	while (m--) {
		int opt = input();
		if (opt == 2) v_all ^= input();
		else {
			int x = input(), y = input();
			printf("%d\n", query(x, y));
		}
	}
	return 0;
}
