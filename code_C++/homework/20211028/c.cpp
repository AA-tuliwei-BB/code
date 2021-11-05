#include <bits/stdc++.h>

using namespace std;

char s[10005], t[10005];
int n, m;

int main() {
	cin.getline(s + 1, 10000);
	cin.getline(t + 1, 10000);

	n = strlen(s + 1);
	m = strlen(t + 1);

	for (int i = 1; i <= n - m + 1; ++i) {
		bool flag = true;
		for (int j = 1; j <= m; ++j)
			if (s[i + j - 1] != t[j]) {
				flag = false;
				break;
			}
		if (flag) {
			cout << i - 1 << endl;
			return 0;
		}
	}

	puts("-1");
	return 0;
}
