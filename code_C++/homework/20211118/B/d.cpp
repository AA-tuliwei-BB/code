#include <bits/stdc++.h>

using namespace std;

string a[100];

int main() {
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = n; i; --i)
		cout << a[i] << endl;
	return 0;
}
