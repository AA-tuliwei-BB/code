#include <bits/stdc++.h>

int n, m;
int mat[15][15];
bool chk[15][15];

int main() {
	std::cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			std::cin >> mat[i][j], chk[i][j] = true;

	for (int i = 1; i <= n; ++i) {
		int max = 0;
		for (int j = 1; j <= m; ++j)
			max = std::max(max, mat[i][j]);
		for (int j = 1; j <= m; ++j)
			if (mat[i][j] != max) chk[i][j] = false;
	}

	for (int j = 1; j <= m; ++j) {
		int min = 0x3f3f3f3f;
		for (int i = 1; i <= n; ++i)
			min = std::min(min, mat[i][j]);
		for (int i = 1; i <= n; ++i)
			if (mat[i][j] != min) chk[i][j] = false;
	}

	bool flag = false;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			if (chk[i][j]) {
				flag = true;
				printf("mat[%d][%d]=%d\n", i - 1, j - 1, mat[i][j]);
			}
	if (!flag) puts("Not Found");
	return 0;
}
