#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int * a = new int [n];
    int * b = new int [m];
    int tmp, * p1, * p2;

	for (p1 = a; p1 < a + n; ++p1) cin >> *p1;
	for (p1 = b; p1 < b + m; ++p1) cin >> *p1;

	for (p1 = a, p2 = b, tmp = 0; tmp < min(n, m); ++tmp, ++p1, ++p2)
		swap(*p1, *p2);

	for (p1 = a; p1 < a + n; ++p1) cout << *p1 << " \n"[p1 == a + n - 1];
	for (p1 = b; p1 < b + m; ++p1) cout << *p1 << " \n"[p1 == b + m - 1];
    return 0;
}
