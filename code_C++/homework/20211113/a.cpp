#include <bits/stdc++.h>

using namespace std;

int C[25][25];

int main() {
	C[0][0] = 1;
	for (int i = 1; i <= 20; ++i) {
		C[i][0] = C[i - 1][0];
		for (int j = 1; j <= 20; ++j)
			C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
	}

	int n, m;
	cin >> n >> m;
	cout << C[n][m] << endl;
	return 0;
}
