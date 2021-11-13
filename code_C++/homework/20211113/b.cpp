#include <bits/stdc++.h>

using namespace std;

int Func(int n) {
	if (n < 1000 || n > 1000000)
		return puts("Input error!"), -1;
	for (int i = 999; i > 99; --i)
		if (n % i == 0) return i;
	return puts("Not found!"), -1;
}

int main() {
	int n;
	cin >> n;
	int a = Func(n);
	if (~a) cout << a << endl;
    return 0;
}
