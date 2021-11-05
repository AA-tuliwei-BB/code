#include <bits/stdc++.h>

using namespace std;

bool notp[105];

void pre_work() {
	notp[1] = true;
	for (int i = 2; i <= 100; ++i) {
		if (notp[i]) continue;
		for (int j = i + i; j <= 100; j += i)
			notp[j] = true;
	}
}

bool isPrime(int n) { return !notp[n]; }

int main() {
    int m, n;
    cin >> m >> n;
	pre_work();

	int ans = 0;
	for (int i = m; i <= n; ++i)
		if (isPrime(i)) ++ans;
	printf("%d\n", ans);
    return 0;
}
