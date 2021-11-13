#include <bits/stdc++.h>

using namespace std;

int Gcd(int m, int n) { return !n ? m : Gcd(n, m % n); }

int main()
{
    int m, n, ans;
    cin >> m >> n;
	int tmp = Gcd(m, n);
	cout << m / tmp << '/' << n / tmp << endl;
    return 0;
}
