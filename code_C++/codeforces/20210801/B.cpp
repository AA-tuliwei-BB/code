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

ll gcd(ll x, ll y) {
	if (!y) return x;
	return gcd(y, x % y);
}

ll myabs(ll x) {
	return x < 0 ? -x : x;
}

int T, n;
int lg[200005];
ll a[200005], b[200005], st[200005][21];

ll query(int l, int r) {
	int Log = lg[r - l];
	return gcd(st[l][Log], st[r - (1 << Log) + 1][Log]);
}

int main() {
//	freopen("in", "r", stdin);
//	freopen("out", "w", stdout);

	for (int i = 2; i <= 200000; ++i)
		lg[i] = lg[i >> 1] + 1;

	T = input();
	while (T--) {
		n = input();
		for (int i = 1; i <= n; ++i)
			scanf("%lld\n", a + i);
		for (int i = 2; i <= n; ++i) {
			b[i - 1] = myabs(a[i] - a[i - 1]);
			st[i - 1][0] = b[i - 1];
		}

		for (int i = 1; i <= lg[n - 1]; ++i) {
			for (int j = n - 1; j; --j) {
				int r = j + (1 << (i - 1));
				if (r < n) st[j][i] = gcd(st[j][i - 1], st[r][i - 1]);
				else st[j][i] = st[j][i - 1];
			}
		}

		int ans = 1;
		for (int i = 1; i < n; ++i) {
			int l = i, r = n - 1, mid, res = i - 1;
			while (l <= r) {
				mid = (l + r) >> 1;
				if (query(i, mid) >= 2)
					res = mid, l = mid + 1;
				else r = mid - 1;
			}
			ans = std::max(ans, res - i + 2);
		}
		printf("%d\n", ans);
	}

	return 0;
}
