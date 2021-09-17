#include <bits/stdc++.h>

int T, n;

int input() {
	int x;
	scanf("%d", &x);
	return x;
}

int main() {
//	freopen("in", "r", stdin);
//	freopen("out", "w", stdout);

	std::cin >> T;

	while (T--) {
		std::cin >> n;
		std::cout << (n + 1) / 10 << '\n';
	}

	return 0;
}
