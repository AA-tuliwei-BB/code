#include <bits/stdc++.h>

using namespace std;

//n points are (x[0],y[0]), (x[1],y[1]), ... ,(x[n-1],y[n-1])
double getMaxTriangle(int n, int x[], int y[])
{
	double res = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = i + 1; j <= n; ++j)
			for (int k = j + 1; k <= n; ++k) {
				double s = ((x[j] - x[i]) * (y[k] - y[i])
						- (x[k] - x[i]) * (y[j] - y[i])) / 2.0l;
				res = max(res, fabs(s));
			}
	return res;
}

int main(void)
{
    int n, x[101], y[101];
	cin >> n;
    assert(3 <= n && n <= 100);
    for (int i=1;i<=n;i++)
        cin >> x[i] >> y[i];
    cout << "max area = " << getMaxTriangle(n, x, y) << endl;
    return 0;
}
