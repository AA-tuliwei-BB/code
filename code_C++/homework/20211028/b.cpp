#include <bits/stdc++.h>

using namespace std;

char s[1000];
int n;

int main() {
	cin >> s + 1;
	n = strlen(s + 1);

	sort(s + 1, s + n + 1);
	n = unique(s + 1, s + n + 1) - s;
	reverse(s + 1, s + n);
	s[n] = 0;

	cout << s + 1 << endl;
	return 0;
}
