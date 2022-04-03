/***********************************************************
  > File Name: c.cpp
  > Author: TALBW
  > Created Time: Sun 20 Mar 2022 07:31:32 PM CST
 *******************************************************/

#include <iostream>
#include <cstdio>

#define int long long

using namespace std;

const int maxn = 4e6;

char stk[maxn + 5];
int top;

int calc(char *s) {
	int pre = 0, now = 0, flag = 0;
	for (int i = 0; s[i]; ++i) {
		if (isdigit(s[i])) now = now * 10 + s[i] - '0';
		else {
			if (flag == 2 and s[i - 1] == '-' and s[i] == '-') {
				flag = 1;
				continue;
			}
			if (flag == 0) pre = now;
			if (flag == 1) pre = now + pre;
			if (flag == 2) pre = pre - now;
			now = 0;

			if (s[i] == '^') return pre ^ calc(s + i + 1);
			if (s[i] == '+') flag = 1;
			if (s[i] == '-') flag = 2;
		}
	}
	if (flag == 0) return now;
	if (flag == 1) return now + pre;
	if (flag == 2) return pre - now;
	exit(1);
}

void write(int x) {
	if (x < 0) stk[++top] = '-', x = -x;
	if (x / 10) write(x / 10);
	stk[++top] = x % 10 + '0';
}

signed main() {
	char ch;
	while ((ch = getchar()) != '\n' and ch != EOF) {
		if (ch == ')') {
			int l = top;
			while (stk[l] != '(') --l;
			int tmp = calc(stk + l + 1);
			for (int i = l; i <= top; ++i) stk[i] = 0;
			top = l - 1;
			write(tmp);
		} else stk[++top] = ch;
	}
	printf("%lld\n", calc(stk + 1));
	return 0;
}
