#include <bits/stdc++.h>

using namespace std;

int main() {
	int n; cin >> n;
	int *a = new int [n + 5];
	char *s = new char [n + 5];
	char *t = new char [n + 5];

	cin >> s + 1;
	for (int i = 1; i <= n; ++i) cin >> a[i], ++ a[i];
	for (int i = 1; i <= n; ++i) t[i] = s[a[i]];
	cout << t + 1 << endl;
	return 0;
}
