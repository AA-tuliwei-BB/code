/***********************************************************
  > File Name: d.cpp
  > Author: TALBW
  > Created Time: Mon 21 Mar 2022 04:16:54 PM CST
 *******************************************************/

#include <cstdio>
#include <iostream>
#define ll long long

int input() {
	int x;
	scanf("%d", &x);
	return x;
}

const int maxn = 2000;

int n, m;
char map[maxn + 5][maxn + 5];
int now[maxn + 5], stk[maxn + 5], pos[maxn + 5], top;
ll sum, cnt, ans;

int main() {
	n = input(), m = input();
	for (int i = 1; i <= n; ++i)
		scanf("%s", map[i] + 1);

	for (int i = 1; i <= n; ++i) {
		cnt = top = sum = 0;
		for (int j = 1; j <= m; ++j) {
			now[j] = map[i][j] == '#' ? 0 : now[j] + 1;
			while (top and stk[top] >= now[j]) {
				ll w = pos[top] - pos[top - 1], h = stk[top];
				ll d = j - 1 - pos[top];
				sum -= w * h * (w + d * 2 + 1) * (h + 1) / 4;
				cnt -= w * h * (h + 1) / 2;
				--top;
			}
			ll w = j - pos[top], h = now[j];
			sum += cnt + w * h * (w + 1) * (h + 1) / 4;
			cnt += (ll) w * h * (h + 1) / 2;
			stk[++top] = now[j], pos[top] = j;
			ans += sum;
		}
	}

	printf("%lld\n", ans);
	return 0;
}
