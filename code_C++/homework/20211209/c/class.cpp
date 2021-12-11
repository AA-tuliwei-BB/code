#include <bits/stdc++.h>
#include "class.h"

using namespace std;

void Roman::SetN(string s) { sscanf(s.c_str(), "%d", &num); }

void Roman::SetR(string s) {
	num = 0;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == 'M') num += 1000;
		else if (s[i] == 'C') {
			if (i + 1 < s.size()) {
				if (s[i + 1] == 'D') { num += 400, ++i; continue; }
				if (s[i + 1] == 'M') { num += 900, ++i; continue; }
			}
			num += 100;
		} else if (s[i] == 'D') num += 500;

		else if (s[i] == 'X') {
			if (i + 1 < s.size()) {
				if (s[i + 1] == 'L') { num += 40, ++i; continue; }
				if (s[i + 1] == 'C') { num += 90, ++i; continue; }
			}
			num += 10;
		} else if (s[i] == 'L') num += 50;

		else if (s[i] == 'I') {
			if (i + 1 < s.size()) {
				if (s[i + 1] == 'V') { num += 4, ++i; continue; }
				if (s[i + 1] == 'X') { num += 9, ++i; continue; }
			}
			++num;
		} else if (s[i] == 'V') num += 5;
	}
}

void Roman::ShowN() { printf("%d\n", num); }
void Roman::ShowR() {
	int now = num;
	while (now >= 1000) cout << 'M', now -= 1000;
	while (now >= 100) {
		if (now >= 900) cout << "CM", now -= 900;
		else if (now >= 500) cout << "D", now -= 500;
		else if (now >= 400) cout << "CD", now -= 400;
		else cout << "C", now -= 100;
	}
	while (now >= 10) {
		if (now >= 90) cout << "XC", now -= 90;
		else if (now >= 50) cout << "L", now -= 50;
		else if (now >= 40) cout << "XL", now -= 40;
		else cout << "X", now -= 10;
	}
	while (now) {
		if (now >= 9) cout << "IX", now -= 9;
		else if (now >= 5) cout << "V", now -= 5;
		else if (now >= 4) cout << "IV", now -= 4;
		else cout << "I", --now;
	}
	cout << endl;
}
