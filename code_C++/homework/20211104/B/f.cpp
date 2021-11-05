#include <bits/stdc++.h>

using namespace std;

void sort(int a[], int n) { sort(a + 1, a + n + 1); }

int a[1005], n;

int main()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
		scanf("%d", a + i);

	sort(a, n);

	int i;
	long long ans = 0;
	for (i = n; i > 3; i -= 2)
		ans += a[1] + a[2] * 2 + max(a[i], a[i - 1]);
	if (i == 2) ans += max(a[1], a[2]);
	else ans += a[1] + a[2] + a[3];
	cout << ans << endl;
    return 0;
}
