/***********************************************************
  > File Name: b.cpp
  > Author: TALBW
  > Created Time: Sun 20 Mar 2022 06:46:04 PM CST
 *******************************************************/

#include <iostream>
#include <cstdio>

using namespace std;

int input() {
	int x; char ch; bool flag = false;
	while (!isdigit(ch = getchar())) if (ch == '-') flag = true;
	for (x = ch ^ 48; isdigit(ch = getchar()); x = x * 10 + ch - '0');
	return flag ? -x : x;
}

const int maxn = 100, maxm = 100000;

int n, m, k;
int p[maxn + 5];
int a[maxn + 5][maxm + 5];
int s[maxm + 5], sum[maxm + 5], Max[maxm + 5];
int id[maxm + 5], que[maxm + 5], head, tail;
int S;

signed main() {
	n = input(), m = input(), k = input();
	for (int i = 1; i <= n; ++i) p[i] = input(), S += p[i];

	for (int i = 1; i <= m; ++i) Max[i] = -0x3f3f3f3f;

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) {
			a[i][j] = input();
			Max[j] = max(Max[j], a[i][j]);
			s[j] += a[i][j] * p[i];
		}

	for (int i = 1; i <= m; ++i)
		sum[i] = sum[i - 1] + s[i];

	for (int i = 1; i < k; ++i) {
		while (que[head] <= Max[i] and head > tail) --head;
		que[++head] = Max[i], id[head] = i;
	}

	int ans = -0x3f3f3f3f;
	for (int i = k; i <= m; ++i) {
		while (que[head] <= Max[i] and head > tail) --head;
		que[++head] = Max[i], id[head] = i;
		if (id[tail + 1] <= i - k) ++tail;
		ans = max(ans, que[tail + 1] * S * k - (sum[i] - sum[i - k]));
	}
	cout << ans << endl;
	return 0;
}
