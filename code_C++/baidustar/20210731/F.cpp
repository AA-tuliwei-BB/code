#include <bits/stdc++.h>
#define inf 0x3f3f3f3f

int input() {
	int x; char ch;
	while (!isdigit(ch = getchar()));
	for (x = ch - '0'; isdigit(ch = getchar()); x = x * 10 + ch - '0');
	return x;
}

int n, a[5000005];
int pa, pb = 1, px = 1;

int main() {
//	freopen("in", "r", stdin);
//	freopen("out", "w", stdout);

	n = input();

	for (int i = 1; i <= n; ++i) {
		int type = input(), x = input();
		if (type == 2) {
			if (x == px) printf("%d\n", pb + 1);
			else printf("%d\n", pa + 1);
		} else {
			a[x] = 1;
			while (a[pa + 1]) ++pa;
			while (a[pb + 1]) ++pb;
			if (x == px && pb < n) {
				px = ++pb;
				while (a[pb + 1]) ++pb;
			}
		}
	}

	return 0;
}
