#include <bits/stdc++.h>

using namespace std;

double Calculate(double x,double y) {
    return 2 / (1 / x + 1 / y);
}

int main() {
	int t;
	cin >> t;
	while (t--) {
    	double x, y;
		cin >> x >> y;
        cout << fixed << setprecision(3) << Calculate(x,y) << endl;
	}
    return 0;
}
