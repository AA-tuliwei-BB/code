#include <bits/stdc++.h>

using namespace std;

int n, a[105];
int p[30] = { 0, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };

bool cmp(int x, int y) {
	vector<int> a, b;
	a.resize(30), b.resize(30);
	for (int i = 1; i <= 25; ++i) {
		while (x % p[i] == 0) ++a[i], x /= p[i];
		while (y % p[i] == 0) ++b[i], y /= p[i];
	}
	return a < b;
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	sort(a + 1, a + n + 1, cmp);
	for (int i = 1; i < n; ++i) cout << a[i] << ' ';
	cout << a[n] << endl;
	return 0;
}
