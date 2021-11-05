#include <bits/stdc++.h>

using namespace std;

int gcd(int x, int y) {
	return !y ? x : gcd(y, x % y);
}

int main() {
	int x, y;
	cin >> x >> y;
	cout << x * y / gcd(x, y) << endl;
	return 0;
}
