#include <bits/stdc++.h>
#define inf 0x3f3f3f3f

int input() {
	int x;
	scanf("%d", &x);
	return x;
}

int T, n, wolf, now;
int kil[55][55];
bool suv[55];

bool Kill(int x) {
	suv[x] = false;
	if (x == wolf) return true;
	else if (--now <= 2) return false;
	else for (int i = 1; i <= n; ++i)
		if (suv[kil[x][i]]) return Kill(kil[x][i]);
}

int main() {
//	freopen("in", "r", stdin);
//	freopen("out", "w", stdout);

	T = input();

	while (T--) {
		now = n = input();
		for (int i = 1; i <= n; ++i) {
			int chk = input();
			if (chk == 1) wolf = i;
			suv[i] = true;
		}

		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				kil[i][j] = input();

		if (Kill(kil[wolf][1])) puts("lieren");
		else puts("langren");
	}

	return 0;
}
