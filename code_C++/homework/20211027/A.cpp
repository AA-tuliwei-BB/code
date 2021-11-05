#include <bits/stdc++.h>

using namespace std;

int n;
int a[100005];

int main() {
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = n; i; --i)
		cout << a[i] << ' ';
	cout << endl;
	return 0;
}
