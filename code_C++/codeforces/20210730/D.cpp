#include <bits/stdc++.h>
#define inf 0x3f3f3f3f

int input() {
	int x;
	scanf("%d", &x);
	return x;
}

int n, m;
char s[200005];
int l[200005], r[200005], ans[200005], sum[200005];
int chk[200005];

void work(char a, char b, char c) {
	for (int i = 1; i <= n; ++i) {
		if (i % 3 == 1) chk[i] = !(s[i] == a);
		if (i % 3 == 2) chk[i] = !(s[i] == b);
		if (i % 3 == 0) chk[i] = !(s[i] == c);
		sum[i] = sum[i - 1] + chk[i];
	}

	for (int i = 1; i <= m; ++i)
		ans[i] = std::min(ans[i], sum[r[i]] - sum[l[i] - 1]);
}

int main() {
//	freopen("in", "r", stdin);
//	freopen("out", "w", stdout);

	n = input(), m = input();
	scanf("%s", s + 1);

	for (int i = 1; i <= m; ++i)
		l[i] = input(), r[i] = input();

	memset(ans, 0x3f, sizeof ans);
	work('a', 'b', 'c');
	work('a', 'c', 'b');
	work('b', 'a', 'c');
	work('b', 'c', 'a');
	work('c', 'a', 'b');
	work('c', 'b', 'a');

	for (int i = 1; i <= m; ++i)
		printf("%d\n", ans[i]);
	return 0;
}
