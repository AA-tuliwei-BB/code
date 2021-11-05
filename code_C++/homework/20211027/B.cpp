#include <bits/stdc++.h>

using namespace std;

map<int, int> mp;

int main() {
	int x;
	while (cin >> x)
		if (!mp[x]) mp[x] = 1, cout << x << ' ';
	cout << endl;
	return 0;
}
