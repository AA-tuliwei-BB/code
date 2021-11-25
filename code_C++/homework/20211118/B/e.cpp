#include <bits/stdc++.h>
#define double long double

using namespace std;

double integrate(double (*pf)(double), double a, double b) {
	double dx = (b - a) / 100000, res = 0;
	for (double i = a; i <= b; i += dx)
		res += pf(i) * dx;
    return res;
}

double f(double x) {
    return exp(-x*x);
}
int main(void) {
    double a, b;
    cin >> a >> b;
    cout << fixed << setprecision(5) << integrate(&f, a, b) << endl;
    return 0;
}
