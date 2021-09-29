#include <bits/stdc++.h>

int main() {
	char a[10];
	std::cin >> a;
	for (int i = 0; i < 4; ++i)
		a[i] = a[i] - '0' + 12 + 'A';
	std::cout << a << std::endl;
	return 0;
}
