#include <bits/stdc++.h>

using namespace std;

int Add(int a, int b) {
	return ((a + b) + 10) % 10;
}

int main() {
	int n, m;
	int a, b, c, d;
	cin >> n >> m;

	a = Add(n / 1000, 7);
	b = Add(n / 100 % 10, 7);
	c = Add(n / 10 % 10, 7);
	d = Add(n % 10, 7);
	cout << c * 1000 + d * 100 + a * 10 + b << ' ';

	a = Add(m / 1000, -7);
	b = Add(m / 100 % 10, -7);
	c = Add(m / 10 % 10, -7);
	d = Add(m % 10, -7);
	cout << c * 1000 + d * 100 + a * 10 + b << '\n';
	return 0;
}
