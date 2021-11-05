#include <bits/stdc++.h>

using namespace std;

// {{{ Date
struct Date {
	int year, month, day;

	bool IsLeapYear() {
		if (year % 4 == 0 and year % 100) return true;
		if (year % 400 == 0) return true;
		return false;
	}

	int Days() {
		int m = month;
		if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8
				|| m == 10 || m == 12) return 31;
		else if (m == 2) return IsLeapYear() ? 29 : 28;
		else return 30;
	}

	bool operator == (Date b) {
		return b.year == year and b.month == month and b.day == day;
	}

	bool operator != (Date b) {
		return !(*this == b);
	}

	bool operator < (Date b) {
		if (year == b.year) 
			if (month == b.month)
				if (day == b.day) return false;
				else return day < b.day;
			else return month < b.month;
		else return year < b.year;
	}

	bool operator > (Date b) {
		if (*this == b) return false;
		else return b < *this;
	}

	void operator ++ () {
		if (day == Days()) {
			day = 1;
			if (month == 12)
				month = 1, ++year;
			else ++month;
		} else ++day;
	}

	void operator -- () {
		if (day == 1) {
			if (month == 1)
				--year, month = 12;
			else --month;
			day = Days();
		} else --day;
	}

	int operator - (Date b) { // result won't be too big
		int res = 0;
		for (; b != *this; ++b) ++res;
		return res;
	}
};
// }}}

int main() {
	int a, b, c;
	Date d, s;
	cin >> a >> b >> c;
	d = (Date) { a, b, c };

	int cnt = 0;
	for (Date s = (Date) { 1990, 1, 1 }; s != d; ++s) ++cnt;
	cnt %= 5;
	if (cnt < 3) puts("Fishing");
	else puts("Sleeping");
	return 0;
}
