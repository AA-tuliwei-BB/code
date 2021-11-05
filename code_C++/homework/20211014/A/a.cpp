#include <bits/stdc++.h>

using namespace std;

bool IsXNumber(int x) {
	int s = 0;
	for (int i = x; i; i /= 10) {
		int t = i % 10;
		s += t * t * t;
	}
	return s == x;
}

int main() {
	int a, b;
	cin >> a >> b;
	if (a > 1e6) return puts("no"), 0;
	if (b > 1e6) b = 1e6;

	bool flag = false;
	for (int i = a; i <= b; ++i)
		if (IsXNumber(i)) cout << i << ' ', flag = true;
	puts(flag ? "" : "no");
	return 0;
}
