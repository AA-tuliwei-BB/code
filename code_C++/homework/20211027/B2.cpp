#include <bits/stdc++.h>

using namespace std;

char s[100], c;

int main() {
	cin.getline(s + 1, 100), c = getchar();
	int pos = 0, len = strlen(s + 1);

	for (int i = 1; i <= len; ++i)
		if (s[i] == c) pos = i;
	if (pos) cout << "Index=" << pos - 1 << endl;
	else puts("Not Found");
	return 0;
}
