#include <bits/stdc++.h>

using namespace std;

map <vector<int>, int> mp;

bool f(vector<int> a) {
	for (int i = 0; i < a.size(); ++i) {
		if (a[i] == 0) {
			if (!i) return true;
			vector<int> b = a;
			b.resize(i);
			if (!f(b)) return true;
		}

		else {
			vector<int> b = a;
			for (int j = 0; j < a[i]; ++j) {
				b[i] = j;
				if (!f(b)) return true;
			}
		}
	}
	return false;
}

int main() {
	int n;
	cin >> n;
	vector<int> a;
	a.resize(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	if (f(a)) puts("X");
	else puts("Y");
	return 0;
}
