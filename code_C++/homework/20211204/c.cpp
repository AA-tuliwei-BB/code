#include <bits/stdc++.h>

using namespace std;

struct Student {
	string name;
	int year, month, day;
	string phone;
	string pos;
	void input() {
		cin >> name >> year >> month >> day >> phone, getchar();
		getline(cin, pos);
	}
	void output() {
		cout << name << ' ' << year << ' ' << month << ' ';
		cout << day << ' ' << phone << ' ' << pos << endl;
	}
	bool operator < (Student b) {
		if (year == b.year)
			if (month == b.month) return day > b.day;
			else return month > b.month;
		else return year > b.year;
	}
}s[15];

int n;

int main() {
	cin >> n;
	for (int i = 1; i <= n; ++i) s[i].input();

	sort(s + 1, s + n + 1);

	for (int i = 1; i <= n; ++i)
		s[i].output();
	return 0;
}
