#include <bits/stdc++.h>
#define inv(x) Power(x, mod - 2)
#define inf 0x3f3f3f3f
#define ll long long

int input() {
	int x;
	scanf("%d", &x);
	return x;
}

const int mod = 998244353;
inline void inc(int &x, int y) { x += y; if (x > mod) x -= mod; }
inline int add(int x, int y) { return x + y > mod ? x + y - mod : x + y; }
inline int mul(int x, int y) { return (ll) x * y % mod; }

inline int Power(int x, int y) {
	int res = 1;
	while (y) {
		if (y & 1) res = mul(res, x);
		x = (ll) x * x % mod, y >>= 1;
	} return res;
}

int n, m, q, ans;
int cnt[200005];

int main() {
//	freopen("in", "r", stdin);
//	freopen("out", "w", stdout);

	ans = n = input(), m = input();
	for (int i = 1; i <= m; ++i) {
		int u = input(), v = input();
		if (u > v) std::swap(u, v);
		if (!cnt[u]++) --ans;
	}

	q = input();
	while (q--) {
		int type = input();
		if (type == 1) {
			int u = input(), v = input();
			if (u > v) std::swap(u, v);
			if (!cnt[u]++) --ans;
		}

		else if (type == 2) {
			int u = input(), v = input();
			if (u > v) std::swap(u, v);
			if (!--cnt[u]) ++ans;
		} else printf("%d\n", ans);
	}

	return 0;
}
