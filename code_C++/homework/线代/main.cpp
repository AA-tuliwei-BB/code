#include <bits/stdc++.h>

using namespace std;

const int n = 5;
long double a[n + 1][n + 2];

int main() {
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n + 1; ++j)
			cin >> a[i][j];

	for (int i = 1; i <= n; ++i) {
		if (fabs(a[i][i]) < 1e-6) {
			for (int j = i + 1; j <= n; ++j)
				if (fabs(a[j][i]) > 1e-6) {
					swap(a[i], a[j]);
					break;
				}
		}
		for (int j = i + 1; j <= n; ++j) {
			long double tmp = a[j][i] / a[i][i];
			for (int k = 1; k <= n + 1; ++k)
				a[j][k] -= a[i][k] * tmp;
		}
	}

	for (int i = n; i; --i) {
		if (a[i][i] == 0) continue;
		a[i][n + 1] /= a[i][i], a[i][i] = 1;
		for (int j = i - 1; j; --j) {
			a[j][n + 1] -= a[i][n + 1] * a[j][i];
			a[j][i] = 0;
		}
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n + 1; ++j)
			printf("%5.0Lf ", a[i][j]);
		puts("");
	}
	return 0;
}
