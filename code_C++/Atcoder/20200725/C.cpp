#include <bits/stdc++.h>

int input() {
	int x;
	scanf("%d", &x);
	return x;
}

int n;
int a[55], b[55];
int fac[4000005], tot;
int fact[1000005], tota;

void get_factor(int x) {
	int MAX = sqrt(x);
	for (int i = 1; i <= sqrt(x); ++i) {
		if (x % i) continue;
		fac[++tot] = i;
		fac[++tot] = x / i;
	}
}

int gcd(int x, int y) {
	if (!y) return x;
	return gcd(y, x % y);
}

long long lcm(int x, int y) {
	return (long long) x * y / gcd(x, y);
}

int main() {
//	freopen("in", "r", stdin);
//	freopen("out", "w", stdout);

	n = input();
	for (int i = 1; i <= n; ++i)
		a[i] = input(), b[i] = input();

	for (int i = 1; i <= n; ++i)
		get_factor(a[i]), get_factor(b[i]);
	std::sort(fac + 1, fac + tot + 1);
	
	for (int l = 1, r = 1; l <= tot; l = r) {
		while (fac[l] == fac[r]) ++r;
		int cnt = r - l, x = fac[l];
		if (cnt < n) continue;

		bool flag = true;
		for (int i = 1; i <= n; ++i)
			if (a[i] % x && b[i] % x)
				flag = false;
		if (flag) fact[++tota] = x;
	}

	long long ans = 0;
	for (int i = 1; i <= tota; ++i) {
		for (int j = i; j <= tota; ++j) {
			if (gcd(fact[i], fact[j]) > 1) continue;
			bool flag = true;
			for (int k = 1; k <= n; ++k) {
				if (a[k] % fact[i])
					if (a[k] % fact[j]) flag = false;
				if (b[k] % fact[i])
					if (b[k] % fact[j]) flag = false;
			}

			if (flag) 
				ans = std::max(ans, lcm(fact[i], fact[j]));
		}
	}

	printf("%lld\n", ans);
	return 0;
}
