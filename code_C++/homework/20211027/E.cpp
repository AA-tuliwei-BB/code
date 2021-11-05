#include <bits/stdc++.h>

using namespace std;

char s[10005];
int n = 0, pl, pr, cnt, ans;

inline bool equal(char a, char b) {
	if (a == b) return true;
	if (isalpha(a) and isalpha(b))
		return toupper(a) == toupper(b);
	return false;
}

int next_l(int p) {
	for (int i = p - 1; i; --i)
		if (isalpha(s[i])) return i;
	return 0;
}

int next_r(int p) {
	for (int i = p + 1; i <= n; ++i)
		if (isalpha(s[i])) return i;
	return n + 1;
}

int search(int l, int r, int& resl, int& resr) {
	int res = l != r ? 2 : isalpha(s[l]) ? 1 : 0;
	resl = l, resr = r;
	while (true) {
		l = next_l(l), r = next_r(r);
		if (!equal(s[l], s[r])) break;
		resl = l, resr = r, res += 2;
	}
	return res;
}

int main() {
	char tmp;
	while ((tmp = getchar()) != EOF) s[++n] = tmp;
	s[n + 1] = '*';

	for (int i = 1; i < n; ++i) {
		int t, tl, tr;
		t = search(i, i, tl, tr);
		if (t > ans) pl = tl, pr = tr, ans = t;
		
		if (isalpha(s[i]) and isalpha(s[i + 1])
				and equal(s[i], s[i + 1])) {
			t = search(i, i + 1, tl, tr);
			if (t > ans) pl = tl, pr = tr, ans = t;
		}
	}

	printf("%d\n", ans);
	for (int i = pl; i <= pr; ++i) putchar(s[i]);
	putchar('\n');
	return 0;
}
