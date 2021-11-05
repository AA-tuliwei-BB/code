#include <bits/stdc++.h>

using namespace std;

int f(int x) {
	int res = 0;
	for (int i = x; i; i /= 10)
		res += i % 10;
	return res;
}

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= 10; ++i) n = f(n);
	cout << n << endl;
	return 0;
}
