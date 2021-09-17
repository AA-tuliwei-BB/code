#include <bits/stdc++.h>

int T, n, m;
char s[100005], t[100005];

int input() {
	int x;
	scanf("%d", &x);
	return x;
}

int main() {
//	freopen("in", "r", stdin);
//	freopen("out", "w", stdout);

	T = input();

	while (T--) {
		for (int i = 1; i <= n; ++i) s[i] = 0;
		for (int i = 1; i <= m; ++i) t[i] = 0;
		scanf("%s", s + 1), n = strlen(s + 1);
		scanf("%s", t + 1), m = strlen(t + 1);
		std::reverse(s + 1, s + n + 1);
		std::reverse(t + 1, t + m + 1);

		int now = 1, i;
		for (i = 1; i <= m and now <= n;) {
			while (t[i] != s[now] and now <= n) now += 2;
			if (t[i] == s[now]) ++i, ++now;
		}
		if (i == m + 1) puts("YES");
		else puts("NO");
	}

	return 0;
}
