#include <bits/stdc++.h>
#define inv(x) Power(x, mod - 2)
#define inf 0x3f3f3f3f
#define ll long long
#define ld long double

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

const int maxn = 500000, maxm = 500000;
char s[maxn + 5];
int n;

int main() {
//	freopen("in", "r", stdin);
//	freopen("out", "w", stdout);

	scanf("%s", s + 1);
	n = strlen(s + 1);

	long long sum = 0;
	for (int i = 1; i <= n; ++i)
		if (s[i] == 'A' or s[i] == 'E' or s[i] == 'O'
				or s[i] == 'I' or s[i] == 'U' or s[i] == 'Y')
			sum += (ll) i * (n - i + 1);

	printf("%.6Lf", (ld) sum / ((ll) n * (n + 1) / 2));
	return 0;
}
