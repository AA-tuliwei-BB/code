#include <bits/stdc++.h>
#define inf 0x3f3f3f3f

int input() {
	int x;
	scanf("%d", &x);
	return x;
}

int n, m, ans = inf;
struct Seg {
	int l, r, w;
} seg[300005];

bool cmp(Seg a, Seg b) { return a.w < b.w; }

namespace Segment {
	int t[8000005], tag[8000005];
#define ls rt << 1
#define rs rt << 1 | 1

	void add(int rt, int v) {
		t[rt] += v;
		tag[rt] += v;
	}

	void pushdown(int rt) {
		add(ls, tag[rt]);
		add(rs, tag[rt]);
		tag[rt] = 0;
	}

	void update(int rt) {
		t[rt] = std::min(t[ls], t[rs]);
	}

	void Add(int rt, int l, int r, int L, int R, int v) {
		if (L <= l && r <= R) return add(rt, v);
		int mid = (l + r) >> 1;
		pushdown(rt);
		if (L <= mid) Add(ls, l, mid, L, R, v);
		if (mid < R) Add(rs, mid + 1, r, L, R, v);
		update(rt);
	}

	void Add(int l, int r, int v) {
		Add(1, 1, m - 1, l, r, v);
	}

	int check() { return t[1] > 0; }
}

int main() {

	n = input(), m = input();
	for (int i = 1; i <= n; ++i)
		seg[i].l = input(), seg[i].r = input(), seg[i].w = input();
	std::sort(seg + 1, seg + n + 1, cmp);

	for (int l = 1, r = 0; r <= n; ) {
		while (!Segment::check()) {
			if (++r > n) goto End;
			Segment::Add(seg[r].l, seg[r].r - 1, 1);
		}

		while (Segment::check()) {
			ans = std::min(ans, seg[r].w - seg[l].w);
			Segment::Add(seg[l].l, seg[l].r - 1, -1), ++l;
		}
	}

End:;
	printf("%d\n", ans);
	return 0;
}
