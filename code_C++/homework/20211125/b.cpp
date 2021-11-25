#include <bits/stdc++.h>

using namespace std;

int maxPair(int a[], int n) {
	int maxa = 0, maxb = 0;
	for (int i = 0; i < n; ++i)
		if (a[i] > maxa) maxb = maxa, maxa = a[i];
		else if (a[i] > maxb) maxb = a[i];
    return maxa + maxb;
}
int main(void) {
    int n; cin >> n;
    int * a = new int [n+1];
    for (int i=0;i<n;i++) cin >> a[i];
    cout << maxPair(a, n) << endl;
	delete [] a;
    return 0;
}
