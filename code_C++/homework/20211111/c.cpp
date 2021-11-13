#include <bits/stdc++.h>

using namespace std;

int f(int n) {
	return n == 1 ? 10 : f(n - 1) + 2;
}

int main() {
	int n;
	cin >> n;
	cout << f(n) << endl;
	return 0;
}
