#include <bits/stdc++.h>

using namespace std;

int p[105], tot;
bool nop[105];

int main() {
	nop[1] = false;
	for (int i = 2; i <= 100; ++i) {
		if (nop[i]) continue;
		for (int j = i + i; j <= 100; j += i)
			nop[j] = true;
		p[++tot] = i;
	}

	int n, ans = 0; cin >> n;
	for (int i = 1; i <= tot; ++i)
		if (n % p[i] == 0) printf("%d ", p[i]);
	putchar('\n');
	return 0;
}
