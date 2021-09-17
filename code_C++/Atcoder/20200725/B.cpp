#include <bits/stdc++.h>

int input() {
	int x;
	scanf("%d", &x);
	return x;
}

int n, tota, tot;
int a[2005], b[2005];
int tmp[4000005], c[4000005], cnt[4000005];
int Ans[2005], tot_ans;

int main() {
//	freopen("in", "r", stdin);
//	freopen("out", "w", stdout);

	n = input();

	for (int i = 1; i <= n; ++i) a[i] = input();
	for (int i = 1; i <= n; ++i) b[i] = input();

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			tmp[++tota] = a[i] ^ b[j];

	std::sort(tmp + 1, tmp + tota + 1);

	c[++tot] = tmp[1], cnt[tot] = 1;
	for (int i = 2; i <= tota; ++i)
		if (tmp[i] != tmp[i - 1]) c[++tot] = tmp[i], cnt[tot] = 1;
		else ++cnt[tot];

	std::sort(a + 1, a + n + 1);
	for (int i = 1; i <= tot; ++i) {
		if (cnt[i] < n) continue;
		for (int j = 1; j <= n; ++j)
			tmp[j] = b[j] ^ c[i];
		std::sort(tmp + 1, tmp + n + 1);

		bool flag = true;
		for (int j = 1; j <= n; ++j)
			if (a[j] != tmp[j])
				flag = false;
		if (flag) Ans[++tot_ans] = c[i];
	}

	printf("%d\n", tot_ans);
	for (int i = 1; i <= tot_ans; ++i)
		printf("%d\n", Ans[i]);
	return 0;
}
