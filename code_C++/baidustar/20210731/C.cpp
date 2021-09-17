#include <bits/stdc++.h>
#define inf 0x3f3f3f3f

int input() {
	int x;
	scanf("%d", &x);
	return x;
}

int T, n, m, k;
int f[100005];

int main() {
//	freopen("in", "r", stdin);
//	freopen("out", "w", stdout);

	T = input();

	while (T--) {
		memset(f, 0x3f, sizeof f);
		n = input(), m = input(), k = input();
		f[k] = 0;

		for (int i = 1; i <= m; ++i) {
			int u = input(), v = input();
			int fu = std::min(f[u] + 1, f[v]);
			int fv = std::min(f[v] + 1, f[u]);
			f[u] = fu, f[v] = fv;
		}

		for (int i = 1; i <= n; ++i) {
			printf("%d", f[i] == inf ? -1 : f[i]);
			putchar(i == n ? '\n' : ' ');
		}
	}

	return 0;
}
