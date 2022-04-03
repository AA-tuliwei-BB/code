/***********************************************************
  > File Name: 1472.cpp
  > Author: TALBW
  > Created Time: Thu 10 Mar 2022 06:45:39 PM CST
 *******************************************************/

#include <bits/stdc++.h>

const int maxn = 5e5, maxm = 150000;

inline int input() {
	int x; char ch;
	while (!isdigit(ch = getchar()));
	for (x = ch ^ 48; isdigit(ch = getchar()); x = x * 10 + (ch ^ 48));
	return x;
}

inline void chkmax(int &x, int y) { x = x < y ? y : x; }
inline void chkmin(int &x, int y) { x = x < y ? x : y; }

struct Query {
	int l, r, k, ans;
} q[maxm + 5];

int n, m, now;
int a[maxn + 5], b[maxn + 5], c[maxm + 5], lsh[maxn + 5];

namespace SegmentTree {
#define ls rt << 1
#define rs rt << 1 | 1
#define mid ((l + r) >> 1)
	const int MAX = maxn << 3;
	int maxl[MAX + 5], maxr[MAX + 5], max[MAX + 5], pd[MAX + 5];

	void update(int rt) {
		max[rt] = std::max(max[ls], max[rs]);
		chkmax(max[rt], maxr[ls] + maxl[rs]);
		maxl[rt] = pd[ls] ? max[ls] + maxl[rs] : maxl[ls];
		maxr[rt] = pd[rs] ? max[rs] + maxr[ls] : maxr[rs];
		pd[rt] = pd[ls] & pd[rs];
	}

	void modify(int rt, int l, int r, int p, int x) {
		if (l == r) {
			maxl[rt] = maxr[rt] = max[rt] = pd[rt] = x;
			return void();
		}
		if (p <= mid) modify(ls, l, mid, p, x);
		else modify(rs, mid + 1, r, p, x);
		update(rt);
	}

	void modify(int p, int x) { modify(1, 1, n, p, x); }

	void query(int rt, int l, int r, int L, int R, int &maxR, int &Max) {
		if (L <= l and r <= R) {
			chkmax(Max, max[rt]);
			chkmax(Max, maxR + maxl[rt]);
			if (pd[rt]) maxR = max[rt] + maxR;
			else maxR = maxr[rt];
			return void();
		}
		if (L <= mid) query(ls, l, mid, L, R, maxR, Max);
		if (mid < R) query(rs, mid + 1, r, L, R, maxR, Max);
	}

	int query(int l, int r) {
		int maxR = 0, Max = 0, pd = 0;
		query(1, 1, n, l, r, maxR, Max);
		return Max;
	}
#undef mid
#undef ls
#undef rs
}

void work(int l, int r, int L, int R) {
	if (l > r or L > R) return void();
	int mid = (l + r) >> 1;
	while (now <= n and a[b[now]] < mid) SegmentTree::modify(b[now++], 0);
	while (a[b[now - 1]] >= mid) SegmentTree::modify(b[--now], 1);

	int tmp = L;
	for (int i = L; i <= R; ++i) {
		if (SegmentTree::query(q[c[i]].l, q[c[i]].r) >= q[c[i]].k)
			q[c[i]].ans = mid;
		else {
			if (tmp != i) std::swap(c[tmp], c[i]);
			++tmp;
		}
	}

	work(l, mid - 1, L, tmp - 1);
	work(mid + 1, r, tmp, R);
}

inline bool cmp(int x, int y) { return a[x] < a[y]; }

int main() {
	n = input();
	for (int i = 1; i <= n; ++i)
		lsh[i] = a[i] = input(), b[i] = i;
	std::sort(lsh + 1, lsh + n + 1);
	for (int i = 1; i <= n; ++i)
		a[i] = std::lower_bound(lsh + 1, lsh + n + 1, a[i]) - lsh;
	std::sort(b + 1, b + n + 1, cmp);

	for (int i = 1; i <= n; ++i)
		SegmentTree::modify(b[i], 1);
	now = 1;

	m = input();
	for (int i = 1; i <= m; ++i)
		q[i].l = input(), q[i].r = input(), q[i].k = input();

	for (int i = 1; i <= m; ++i) c[i] = i;
	work(1, n, 1, m);

	for (int i = 1; i <= m; ++i) {
		//printf("%d\n", q[i].ans);
		printf("%d\n", lsh[q[i].ans]);
	}
	return 0;
}
