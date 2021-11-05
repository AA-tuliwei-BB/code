#include <bits/stdc++.h>

using namespace std;

void printInt(int n,int base) {
	if (!n) return;
	int a = n % base;
	printInt(n / base, base);
	putchar(a < 10 ? a + '0' : a + 'A' - 10);
}

int main() {
    int n, base;
    cin >> n >> base;
    printInt(n, base);
    return 0;
}
