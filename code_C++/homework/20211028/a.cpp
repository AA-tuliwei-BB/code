#include <bits/stdc++.h>

using namespace std;

int main() {
	char c;
	int cnt = 0;

	while (cin >> c) {
		c = tolower(c);
		if (c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u')
			++cnt;
	}

	printf("Count=%d\n", cnt);
	return 0;
}
