#include <bits/stdc++.h>
#include "class.h"

using namespace std;

void Matrix::Initialization() {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			cin >> a[i][j];
}

void Matrix::Transpose() {
	for (int j = 1; j <= m; ++j) {
		for (int i = 1; i <= n; ++i)
			cout << a[i][j] << (i == n ? '\n' : ' ');
	}
}

void Matrix::Determinant() {
	const double eps = 1e-6;
	if (n != m) return puts("@"), void();
	for (int i = 1; i <= n; ++i) {
		if (-eps < a[i][i] and a[i][i] < eps)
			for (int j = i + 1; j <= n; ++j)
				if (a[j][i]) {
					swap(a[i], a[j]);
					break;
				}
		if (-eps < a[i][i] and a[i][i] < eps)
			return puts("0"), void();
		for (int j = i + 1; j <= n; ++j) {
			double tmp = a[j][i] / a[i][i];
			for (int k = i; k <= n; ++k)
				a[j][k] -= a[i][k] * tmp;
		}
	}

	double res = 1;
	for (int i = 1; i <= n; ++i)
		res *= a[i][i];
	cout << res << endl;
}
