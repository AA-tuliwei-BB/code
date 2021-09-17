#include <bits/stdc++.h>

int input() {
	int x;
	scanf("%d", &x);
	return x;
}

char s[10];
std::bitset<1005> tag[1005];
int n, k;

int main() {
//	freopen("in", "r", stdin);
//	freopen("out", "w", stdout);

	n = input(), k = input();
	for (int i = 1; i <= n; ++i)
		tag[i].set();

	for (int i = 1, p; i <= k; ++i) {
		scanf("%s%d", s, &p);
		tag[p].reset();
		tag[p][i] = 1;

		if (s[0] == 'L')
			for (int j = p - 1; j; --j)
				tag[j][i] = 0;
		else for (int j = p + 1; j <= n; ++j)
			tag[j][i] = 0;
	}

	long long ans = 1;
	for (int i = 1; i <= n; ++i) {
		int cnt = 0;
		for (int j = 1; j <= k; ++j)
			cnt += tag[i][j];
		ans = ans * cnt % 998244353;
	}

	printf("%lld\n", ans);
	return 0;
}
