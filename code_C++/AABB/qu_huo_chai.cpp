#include <bits/stdc++.h>

using namespace std;

int cnt;
int y;

int main() {
	srand(time(0));

	cnt = rand() % 50 + 50;
	//y = rand() % 40 + 1;
	y = 40;
	printf("%d\n", y);

	while (true) {
		int x;
		puts("It's Bob's turn.");
		printf("How many (%d left) : ", cnt);
		cin >> x;
		cnt -= x;

		if (x < 1 || x > y) {
			puts("Alice win!!!");
			break;
		}
		if (!cnt) {
			puts("Bob win!!!");
			break;
		}
		if (cnt < 0) {
			puts("Alice win!!!");
			break;
		}

		puts("It's Alice's turn.");
		printf("How many (%d left, 1) : ", cnt);
		cin >> x;
		cnt -= x;

		if (x < 1 || x > y) {
			puts("Bob win!!!");
			break;
		}
		if (!cnt) {
			puts("Alice win!!!");
			break;
		}
		if (cnt < 0) {
			puts("Bob fail!!!");
			break;
		}
	}

	return 0;
}
