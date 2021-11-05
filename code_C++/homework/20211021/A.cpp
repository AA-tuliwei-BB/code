#include <bits/stdc++.h>

using namespace std;

int n, k;
int a[10005];
int open[10005];

int main() {
	cin >> n >> k;
	for (int i = 1; i <= k; ++i)
		for (int j = i; j <= n; j += i)
			open[j] ^= 1;

	for (int i = 1; i <= n; ++i)
		if (open[i]) cout << i << ' ';
	cout << endl;
	return 0;
}
