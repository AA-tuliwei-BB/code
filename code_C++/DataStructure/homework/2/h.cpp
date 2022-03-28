/***********************************************************
  > File Name: h.cpp
  > Author: TALBW
  > Created Time: Tue 22 Mar 2022 07:11:04 PM CST
 *******************************************************/

#include <iostream>
#include <cstdio>

int input() {
	int x; char ch; bool flag = false;
	while (!isdigit(ch = getchar())) if (ch == '-') flag = true;
	for (x = ch ^ 48; isdigit(ch = getchar()); x = x * 10 + (ch ^ 48));
	return flag ? -x : x;
}

const int maxn = 1e6;

int n;
int l[maxn + 5], r[maxn + 5];
int que[maxn + 5], pos[maxn + 5], tail = 1, head;

inline void chkmin(int &x, int y) { x = x < y ? x : y; }
inline void chkmax(int &x, int y) { x = x < y ? y : x; }

int main() {
	n = input();
	for (int i = 1; i <= n; ++i) l[i] = input(), r[i] = input();

	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		while (tail <= head and que[tail] > r[i]) ++tail;
		if (tail <= head and que[head] < l[i]) que[head] = l[i];
		while (tail < head and que[head - 1] <= que[head])
			que[head - 1] = que[head], --head;
		if (tail > head or que[head] > l[i])
			que[++head] = l[i], pos[head] = i;
		chkmax(ans, i - pos[tail] + 1);
	}

	printf("%d\n", ans);
	return 0;
}
