/***********************************************************
  > File Name: 21points.cpp
  > Author: TALBW
  > Created Time: Mon 03 Jan 2022 09:09:38 PM CST
 *******************************************************/

#include <bits/stdc++.h>

using namespace std;

int money = 100;
int card[55];

void init() {
	system("clear");
	puts("Game start!!!");
	for (int i = 1; i <= 13; ++i) {
		int j = i * 4;
		if (i > 10)
			card[j] = card[j - 1] = card[j - 2] = card[j - 3] = 10;
		else card[j] = card[j - 1] = card[j - 2] = card[j - 3] = i;
	}
	random_shuffle(card + 1, card + 53);
}

void Menu() {
	system("clear");
	printf("You have %d$ now.\n", money);
	puts("Start or quit? (s/q) ");
	char opt[10];
	while (true) {
		cin >> opt;
		if (opt[0] == 's') return void();
		if (opt[0] == 'q') exit(0);
		puts("Input 's' or 'q' please");
	}
}

int calc(vector<int> p) {
	int res = 0;
	sort(p.begin(), p.end());
	reverse(p.begin(), p.end());
	for (auto i : p) {
		if (i != 1) res += i;
		else res += res <= 10 ? 11 : 1;
	}
	return res;
}

void work() {
	if (money <= 0) {
		system("clear");
		puts("You are broken!!!");
		exit(0);
	}

	Menu();
	init();

	int now = 1;
	vector<int> p, c;
	while (true) {
		p.push_back(card[now]);
		if (calc(p) > 21) {
			system("clear");
			puts("GG");
			system("pause");
			money -= 10;
			return void();
		}
		puts("");
		if (card[now] == 1) puts("You get a 'A'");
		else printf("You get a '%d'.\n", card[now]);
		++now;
		puts("Now your cards are:");
		for (int i = 0; i < p.size(); ++i) {
			if (p[i] == 1) printf("A ");
			else printf("%d ", p[i]);
		}
		puts("");
		printf("Continue? (y/n)");
		char opt[10];
A:;
		cin >> opt;
		if (opt[0] == 'n') break;
		if (opt[0] == 'y' or opt[0] == 'Y') continue;
		puts("Input 'y' or 'n' please!");
		goto A;
	}

	int PointsOfPlayer1 = calc(p), PointsOfPlayer2 = 0;
	while (calc(c) <= 21) {
		PointsOfPlayer2 = calc(c);
		c.push_back(card[now++]);
	}

	if (PointsOfPlayer1 > PointsOfPlayer2) {
		system("clear");
		puts("You win!!!");
		system("pause");
		money += 10;
		return void();
	} else {
		system("clear");
		puts("GG");
		system("pause");
		money -= 10;
		return void();
	}
}

int main() {
	srand(time(0));
	while (true) work();
	return 0;
}
