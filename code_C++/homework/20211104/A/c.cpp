#include <bits/stdc++.h>

using namespace std;

void valid(int n) {
	while (n != 1) {
		cout << n << ' ';
		n = (n & 1) ? n * 3 + 1 : n >> 1;
	}
	puts("1");
}

int main()
{
    int n;
    cin >> n;
    valid(n);
    return 0;
}
