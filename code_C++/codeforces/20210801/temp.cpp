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

int main() {
//	freopen("in", "r", stdin);
//	freopen("out", "w", stdout);

	return 0;
}
