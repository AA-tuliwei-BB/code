#include <bits/stdc++.h>
#define inf 0x3f3f3f3f

int input() {
	int x;
	scanf("%d", &x);
	return x;
}

int T, a, b;

int main() {
//	freopen("in", "r", stdin);
//	freopen("out", "w", stdout);

	T = input();
	while (T--) {
		a = input(), b = input();
		if (a > b) std::swap(a, b); // make sure a < b
		if (b - a == 1 || (a == b && a == 1)) {
			puts("-1 -1");
			continue;
		}

		if (a == b) {
			printf("%d %d\n", 2, a);
			continue;
		}

		int res = 0;
		for (int i = 2, MAX = sqrt(b - a); i <= MAX; ++i)
			if ((b - a) % i == 0) {
				res = i;
				break;
			}

		if (!res) printf("%d %d\n", b - a, b - a);
		else printf("%d %d\n", res, b - a);
	}

	return 0;
}
