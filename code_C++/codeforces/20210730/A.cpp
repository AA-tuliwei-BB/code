#include <bits/stdc++.h>
#define inf 0x3f3f3f3f

int f[105], m, T;

int input() {
	int x;
	scanf("%d", &x);
	return x;
}

long long work(long long x) {
	if (x & 1) ++x;
	x >>= 1;
	if (x > 100) return x * 5;
	else return f[x];
}

void pre_work() { // 3 -> 15, 4 -> 20, 5 -> 25
	memset(f, 0x3f, sizeof f);
	f[0] = 0;
	for (int i = 1; i <= 100; ++i) {
		if (i >= 3) f[i] = std::min(f[i], f[i - 3] + 15);
		if (i >= 4) f[i] = std::min(f[i], f[i - 4] + 20);
		if (i >= 5) f[i] = std::min(f[i], f[i - 5] + 25);
	}

	for (int i = 99; i; --i)
		f[i] = std::min(f[i], f[i + 1]);
}

int main() {
//	freopen("in", "r", stdin);
//	freopen("out", "w", stdout);

	pre_work();

	T = input();
	while (T--) {
		long long x;
		scanf("%lld", &x);
		printf("%lld\n", work(x));
	}

	return 0;
}
