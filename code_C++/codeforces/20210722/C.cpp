#include <bits/stdc++.h>

int T, n;
char s[100], t[100];

int input() {
	int x;
	scanf("%d", &x);
	return x;
}

int calc() {
	int sa = 0, sb = 0;
	for (int i = 1; i <= 10; ++i) {
		if (t[i] == '1')
			if (i & 1) ++ sa;
			else ++sb;
		if (i & 1) {
			if (sb + (10 - i + 1) / 2 < sa) return i;
			if (sa + (9 - i) / 2 < sb) return i;
		} else {
			if (sb + (10 - i) / 2 < sa) return i;
			if (sa + (9 - i + 1) / 2 < sb) return i;
		}
	}
	return 10;
}

int main() {
//	freopen("in", "r", stdin);
//	freopen("out", "w", stdout);

	T = input();

	while (T--) {
		scanf("%s", s + 1);
		int res = 10;
		for (int i = 1; i <= 10; ++i)
			t[i] = s[i] == '?' ? ((i & 1) ? '1' : '0') : s[i];
		res = std::min(res, calc());

		for (int i = 1; i <= 10; ++i)
			t[i] = s[i] == '?' ? ((i & 1) ? '0' : '1') : s[i];
		res = std::min(res, calc());
		
		printf("%d\n", res);
	}

	return 0;
}
