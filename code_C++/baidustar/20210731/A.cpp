#include <bits/stdc++.h>
#define inv(x) Power(x, mod - 2)
#define inf 0x3f3f3f3f
#define ll long long

int input() {
	int x;
	scanf("%d", &x);
	return x;
}

const int mod = 998244353;
inline void inc(int &x, int y) { x += y; if (x > mod) x -= mod; }
inline int add(int x, int y) { return x + y > mod ? x + y - mod : x + y; }
inline int mul(int x, int y) { return (ll) x * y % mod; }

inline int Power(int x, int y) {
	int res = 1;
	while (y) {
		if (y & 1) res = mul(res, x);
		x = (ll) x * x % mod, y >>= 1;
	} return res;
}

struct Matrix {
	int ma[205][205], n;
	
	void init(int __n) {
		n = __n;
		memset(ma, 0, sizeof ma);
	}
} E, A;

Matrix operator * (Matrix a, Matrix b) {
	int n = a.n;
	Matrix res;
	res.init(n);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j) {
			int sum = 0;
			for (int k = 1; k <= n; ++k)
				inc(sum, mul(a.ma[i][k], b.ma[k][j]));
			res.ma[i][j] = sum;
		}
	return res;
}

Matrix operator ^ (Matrix a, int y) {
	Matrix res;
	res = a, -- y;
	while (y) {
		if (y & 1) res = res * a;
		a = a * a, y >>= 1;
	}
	return res;
}

int T, n, m, k;
int G[105][105], du[105];
int inv[105];

void work() {
	memset(G, 0, sizeof G);
	memset(du, 0, sizeof du);
	n = input(), m = input(), k = input();
	while (m--) {
		int u = input(), v = input(), w = input();
		G[v][u] = G[u][v] = w + 1; // 1 -> 普通 ; 2 -> 附魔
		++ du[u], ++ du[v];
	}

	E.init(n << 1);
	A.init(n << 1);
	A.ma[1][n << 1] = 1;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (!G[i][j]) continue;
			if (G[i][j] == 1) { // normal
				E.ma[j * 2][i * 2] = inv[du[i]];
				E.ma[j * 2 - 1][i * 2 - 1] = inv[du[i]];
			} else { // magic
				E.ma[j * 2 - 1][i * 2] = inv[du[i]];
				E.ma[j * 2][i * 2 - 1] = inv[du[i]];
			}
		}
	}

	A = A * (E ^ k);
	printf("%d\n", A.ma[1][1]);
}

int main() {
//	freopen("in", "r", stdin);
//	freopen("out", "w", stdout);

	for (int i = 1; i <= 100; ++i)
		inv[i] = inv(i);

	T = input();
	while (T--)
		work();

	return 0;
}
