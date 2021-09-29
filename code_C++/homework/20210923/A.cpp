#include <bits/stdc++.h>

int main() {
	int a;
	std::cin >> a;
	printf("%d的百位数字是%d，十位数字是%d，个位数字是%d",
			a, a / 100, a / 10 % 10, a % 10);
	return 0;
}
