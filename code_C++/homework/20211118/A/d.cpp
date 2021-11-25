#include <bits/stdc++.h>

using namespace std;

char * julian(int year, int day) {
    bool isLeap = !(year & 3) and (year % 100 or year % 400 == 0);
	char *s = new char [10];
	if (day > 31) day -= 31;
	else return sprintf(s, "Jan %02d\0", day), s;
	if (day > (isLeap ? 29 : 28)) day -= isLeap ? 29 : 28;
	else return sprintf(s, "Feb %02d\0", day), s;
	if (day > 31) day -= 31;
	else return sprintf(s, "Mar %02d\0", day), s;
	if (day > 30) day -= 30;
	else return sprintf(s, "Apr %02d\0", day), s;
	if (day > 31) day -= 31;
	else return sprintf(s, "May %02d\0", day), s;
	if (day > 30) day -= 30;
	else return sprintf(s, "Jun %02d\0", day), s;
	if (day > 31) day -= 31;
	else return sprintf(s, "Jul %02d\0", day), s;
	if (day > 31) day -= 31;
	else return sprintf(s, "Aug %02d\0", day), s;
	if (day > 30) day -= 30;
	else return sprintf(s, "Sept %02d\0", day), s;
	if (day > 31) day -= 31;
	else return sprintf(s, "Oct %02d\0", day), s;
	if (day > 30) day -= 30;
	else return sprintf(s, "Nov %02d\0", day), s;
	if (day > 31) return NULL;
	return sprintf(s, "Dec %02d\0", day), s;
}

int main() {
    int year, day;
    char * res;
    cin >> year >> day;
    res = julian(year, day);
    if (res) cout << res << endl;
    delete [] res;
    return 0;
}
