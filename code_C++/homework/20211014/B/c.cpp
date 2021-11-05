#include <bits/stdc++.h>

using namespace std;

int main() {
	int a = 0, b = 1, n;
	cin >> n;

	for (int i = 1; i <= n; ++i) {
		int t = b + a;
		a = b, b = t;
	}

	cout << a << endl;
	return 0;
}
