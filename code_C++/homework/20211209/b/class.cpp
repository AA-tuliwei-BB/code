#include "class.h"
#include <bits/stdc++.h>

using namespace std;

void Clock::input() {
	char tmp;
	cin >> hh >> tmp >> mm >> tmp >> ss;
}

void Clock::output() {
	printf("%02d:%02d:%02d\n", hh, mm, ss);
}

bool operator < (Clock a, Clock b) {
	if (a.hh != b.hh) return a.hh < b.hh;
	if (a.mm != b.mm) return a.mm < b.mm;
	return a.ss < b.ss;
}

Clock operator - (Clock a, Clock b) {
	assert(b < a);
	Clock res;
	if (a.ss > b.ss) res.ss = a.ss - b.ss;
	else res.ss = a.ss + 60 - b.ss, ++b.mm;
	if (a.mm > b.mm) res.mm = a.mm - b.mm;
	else res.mm = a.mm + 60 - b.mm, ++b.hh;
	res.hh = a.hh - b.hh;
	return res;
}
