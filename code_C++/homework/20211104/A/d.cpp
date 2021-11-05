#include <bits/stdc++.h>

using namespace std;

int CountDigit(int number,int digit) {
	int res = 0;
	while (number) {
		res += number % 10 == digit;
		number /= 10;
	}
	return res;
}

int main()
{
	int number, digit;
	cin >> number >> digit;
	cout << CountDigit(number, digit) << endl;
	return 0;
}
