#include <bits/stdc++.h>

using namespace std;

int cal_routines(int m ,int n){
	static int dp[1005][1005];
	dp[1][0] = 1;
	for (int i = 1; i <= m; ++i)
		for (int j = 1; j <= n; ++j)
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
	return dp[m][n];
}

int main() {
    int m, n;
    cin >> m >> n;
    cout << cal_routines(m, n) << endl;
	return 0;
}
