#include <bits/stdc++.h>

using namespace std;

int rev(int x) {
	int res = 0;
	for (int i = x; i; i /= 10)
		res = res * 10 + i % 10;
	return res;
}

int main() {
	int n, cnt = 0;
	cin >> n;
	for (int i = 1; i <= n; ++i)
		if (i + rev(i) == n) ++cnt;
	cout << cnt << endl;
	return 0;
}
