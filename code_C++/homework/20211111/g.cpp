#include <bits/stdc++.h>

using namespace std;

int a, b;
int pos[1005], nu[1005];

void print(int a) {
	if (a >> 1) print(a >> 1);
	return putchar((a & 1) + '0'), void();
}

int main() {
	float tmp; cin >> tmp;
	a = int(tmp), b = int((tmp - a) * 100 + 0.5);
	print(a);

	pos[b] = -1;
	int p = 0, n = 0;
	while (true) {
		b <<= 1;
		if (!b) break;
		if (b >= 100) nu[++n] = 1, b -= 100;
		else nu[++n] = 0;
		if (pos[b]) { p = pos[b]; break; }
		pos[b] = n;
	}

	if (n) putchar('.');

	if (p == 0)
		for (int i = 1; i <= n; ++i)
			putchar(nu[i] + '0');
	else {
		if (p == -1) p = 0;
		for (int i = 1; i <= p; ++i)
			putchar(nu[i] + '0');
		putchar('(');
		for (int i = p + 1; i <= n; ++i)
			putchar(nu[i] + '0');
		putchar(')');
	}
	putchar('\n');
	return 0;
}
