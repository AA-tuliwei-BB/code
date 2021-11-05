#include <bits/stdc++.h>

using namespace std;

int main() {
	int a, n, ans = 0;
	cin >> a >> n;
	for (int i = 1, s = a; i <= n; ++i, s = s * 10 + a) ans += s;
	cout << ans << endl;
	return 0;
}
