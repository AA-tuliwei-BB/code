#include <bits/stdc++.h>

using namespace std;

bool perfectNumber(int n) {
	int sum = 1, MAX = ceil(sqrt(n));
	for (int i = 2; i < MAX; ++i)
		if (n % i == 0)
			sum += i + n / i;
	if (MAX * MAX == n) sum += MAX;
	return sum == n;
}

int main() {
    int m, n;
    cin >> m >> n;
	bool flag = true;

	for (int i = m; i <= n; ++i)
		if (perfectNumber(i)) cout << i << ' ', flag = false;
	puts(flag ? "-1" : "");
    return 0;
}
