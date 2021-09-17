#include <bits/stdc++.h>
#define ll long long

int T, n, m;
char s[505], t[1005];

const ll mod = 1e9 + 7, Base = 2333ll;
ll hasha[505], hashb[505], hasht[1005], p[1005];

int input() {
	int x;
	scanf("%d", &x);
	return x;
}

ll get_hash(int l, int r, ll* h) {
	if (l <= r)
		return (h[r] + mod - (h[l - 1] * p[r - l + 1] % mod)) % mod;
	if (l > r)
		return (h[r] + mod - (h[l + 1] * p[l - r + 1] % mod)) % mod;
}

void pre_hash() {
	memset(hasha, 0, sizeof hasha);
	memset(hashb, 0, sizeof hashb);
	memset(hasht, 0, sizeof hasht);

	for (int i = 1; i <= n; ++i)
		hasha[i] = (hasha[i - 1] * Base + s[i]) % mod;
	for (int i = n; i; --i)
		hashb[i] = (hashb[i + 1] * Base + s[i]) % mod;
	for (int i = 1; i <= m; ++i)
		hasht[i] = (hasht[i - 1] * Base + t[i]) % mod;
}

int main() {
//	freopen("in", "r", stdin);
//	freopen("out", "w", stdout);

	p[0] = 1;
	for (int i = 1; i <= 1000; ++i)
		p[i] = p[i - 1] * Base % mod;

	T = input();

	while (T--) {
		memset(s, 0, sizeof s);
		memset(t, 0, sizeof t);
		scanf("%s", s + 1), n = strlen(s + 1);
		scanf("%s", t + 1), m = strlen(t + 1);

		pre_hash();

		for (int i = 1; i <= std::min(n, m); ++i) {
			for (int j = i; j <= n; ++j) {
				int l = j - i + 1, r = j, L, R;
				bool flag = true;
				for (int k = 0; k < i; ++k)
					if (t[1 + k] != s[l + k])
						flag = false;
				//if (get_hash(1, i, hasht) != get_hash(l, r, hasha))
				if (!flag)
					continue;
				if (i == m) {
					//std :: cerr << i << ' ' << j << '\n';
					puts("YES");
					goto End;
				}

				L = i + 1, R = m, l = j - 1, r = l - (R - L);
				if (r <= 0) continue;

				flag = true;
				for (int k = 0; k < R - L + 1; ++k)
					if (t[L + k] != s[l - k]) flag = false;
				
				//if (get_hash(L, R, hasht) == get_hash(l, r, hashb)) {
				if (flag) {
					//std :: cerr << i << ' ' << j << '\n';
					puts("YES");
					goto End;
				}
				
			}
		}

		puts("NO");
End:;
	}

	return 0;
}
