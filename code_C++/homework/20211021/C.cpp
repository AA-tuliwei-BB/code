#include <bits/stdc++.h>

using namespace std;

int n;
int b[1000005];

map<int, bool> mp;

int main() {
	int x;
	while (cin >> x)
		if (!mp[x])
			b[++n] = x, mp[x] = true;
	for (int i = 1; i <= n; ++i)
		cout << b[i] << ' ';
	cout << endl;
	return 0;
}
