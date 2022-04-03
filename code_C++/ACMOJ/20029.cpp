/***********************************************************
  > File Name: T3.cpp
  > Author: TALBW
  > Created Time: Thu 31 Mar 2022 03:50:07 PM CST
 *******************************************************/

#include <iostream>
#include <cstdio>

using namespace std;

int input() {
	int x;
	scanf("%d", &x);
	return x;
}

const int maxn = 1e5, maxbit = 31;

namespace trie {
	int ch[maxn * 31 + 5][2], cnt = 1, root = 1;

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
}

int n, m;

int main() {
	n = input(), m = input();
	for (int i = 1; i <= n; ++i)
		trie::insert(input());
	while (m--) printf("%d\n", trie::query(input()));
	return 0;
}
