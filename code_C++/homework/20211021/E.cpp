#include <bits/stdc++.h>

using namespace std;

int n;
int f[15][15], a[15][15];
bool vis[15][15];

int dfs(int x, int y) {
	if (x == 1) return a[1][1];
	if (vis[x][y]) return f[x][y];
	vis[x][y] = true;

	if (y == 1) return f[x][y] = dfs(x - 1, 1) + a[x][1];
	if (y == x) return f[x][y] = dfs(x - 1, y - 1) + a[x][y];
	else return f[x][y] = max(dfs(x - 1, y), dfs(x - 1, y - 1)) + a[x][y];
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= i; ++j)
			cin >> a[i][j];

	int ans = 0;
	for (int i = 1; i <= n; ++i)
		ans = max(ans, dfs(n, i));
	cout << ans << endl;
	return 0;
}
