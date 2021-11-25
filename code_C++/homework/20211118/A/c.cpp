#include <bits/stdc++.h>

using namespace std;

int next(char *s, int i) {
	int j;
	for (j = i + 1; s[j]; ++j)
		if (s[j] == '@' or s[j] == '$' or s[j] == '#');
		else return j;
	return j;
}

bool work(char *s) {
	bool res = false;
	int n = strlen(s), tot = 0;
	char *t = new char [n];
	for (int i = 0; i < n; ++i)
		if (toupper(s[i]) == 'F') {
			if (toupper(s[next(s, i)]) == 'D')
				res = true, i = next(s, i);
			else t[tot++] = s[i];
		} else if (toupper(s[i]) == 'L') {
			if (s[next(s, i)] == '4')
				res = true, i = next(s, i);
			else t[tot++] = s[i];
		} else t[tot++] = s[i];
	t[tot] = 0;
	strcpy(s, t);
	delete [] t;
	return res;
}

int main() {
	char *s = new char [205];
	cin >> s;
	while (work(s));
	cout << s << endl;
	delete [] s;
	return 0;
}
