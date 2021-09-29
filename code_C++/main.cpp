#include <bits/stdc++.h>
#define inv(x) Power(x, mod - 2)
#define inf 0x3f3f3f3f

typedef long long ll;
typedef long double ld;

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

template <class T> inline void chkmin(T &x, T y) { x = x < y ? x : y; }
template <class T> inline void chkmax(T &x, T y) { x = x > y ? x : y; }

const int maxn = 18, maxm = 10000;

int T, n, m;
int All[maxn + 5][maxn + 5];
ld x[maxn + 5], y[maxn + 5];
int f[1 << 18];

int lowbit(int x) { return x & -x; }

bool equal(ld a, ld b) {
	ld d = a - b;
	d = d < 0 ? -d : d;
	if (d < 1e-8) return true;
	else return false;
}

void GetAll() {
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			ld xa = x[i], xb = x[j];
			ld ya = y[i], yb = y[j];
			if (xa == xb) continue;
			ld a = (xb / xa * ya - yb) / (xa * xb - xb * xb);
			ld b = (xb * xb / xa / xa * ya - yb) / (xb * xb / xa - xb);
			if (a > 0 or equal(a, 0)) continue;

			All[i][j] = 1 << (i - 1) | 1 << (j - 1);
			for (int k = 1; k <= n; ++k) {
				if (k == i or k == j) continue;
				if (equal(y[k], a * x[k] * x[k] + b * x[k]))
					All[i][j] |= 1 << (k - 1);
			}
		}
	}
}

int main() {
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);

	T = input();
	while (T--) {
		n = input(), m = input();
		for (int i = 1; i <= n; ++i)
			scanf("%Lf%Lf", x + i, y + i);
		memset(f, 0x3f, sizeof f);
		f[(1 << n) - 1] = 0;

		memset(All, 0, sizeof All);
		GetAll();

		for (int S = (1 << n) - 1; S; --S) {
			int lb = lowbit(S);
			chkmin(f[S ^ lb], f[S] + 1);

			int lbp = 0;
			for (int i = 0; i < n; ++i) {
				if (not(1 << i & S)) continue;
				if ((1 << i) == lb) {
					lbp = i;
					continue;
				}
				int s = All[lbp + 1][i + 1] & S;
				chkmin(f[S ^ s], f[S] + 1);
			}
		}

		printf("%d\n", f[0]);
	}

	return 0;
}
