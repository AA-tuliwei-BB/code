#include <bits/stdc++.h>
#define inf 0x3f3f3f3f

int input() {
	int x;
	scanf("%d", &x);
	return x;
}

int T, m;
int a[100005], b[100005];

int main() {
//	freopen("in", "r", stdin);
//	freopen("out", "w", stdout);

	T = input();

	while (T--) {
		m = input();
		int s1 = 0, s2 = 0, ans = inf;
		for (int i = 1; i <= m; ++i)
			a[i] = input(), s1 += a[i];
		for (int i = 1; i <= m; ++i)
			b[i] = input();

		for (int i = 1; i <= m; ++i) {
			s1 -= a[i], s2 += b[i - 1];
			ans = std::min(ans, std::max(s1, s2));
		}
		printf("%d\n", ans);
	}

	return 0;
}
