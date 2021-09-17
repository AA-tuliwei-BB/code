#include <bits/stdc++.h>
#define inf 0x3f3f3f3f

int input() {
	int x;
	scanf("%d", &x);
	return x;
}

int T, W, H, w, h, ww, hh;
int xa, ya, xb, yb;

int main() {
//	freopen("in", "r", stdin);
//	freopen("out", "w", stdout);

	T = input();

	while (T--) {
		int ans = 0x3f3f3f3f;
		W = input(), H = input();
		xa = input(), ya = input();
		xb = input(), yb = input();
		ww = xb - xa, hh = yb - ya;
		w = input(), h = input();

		if (w + ww <= W) {
			ans = std::min(ans, w - xa); // l
			ans = std::min(ans, w - (W - xb)); // r
		}

		if (h + hh <= H) {
			ans = std::min(ans, h - ya); // d
			ans = std::min(ans, h - (H - yb)); // u
		}

		ans = std::max(ans, 0);
		printf("%d\n", ans == inf ? -1 : ans);
	}

	return 0;
}
