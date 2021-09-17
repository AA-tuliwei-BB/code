#include <bits/stdc++.h>

// blue      -> b  -> 1
// darkblue  -> db -> 2
// green     -> g  -> 3
// darkgreem -> dg -> 4
// purple    -> pp -> 5
// pink      -> pk -> 6
// grey      -> gy -> 7
// red       -> r  -> 8
// orange    -> o  -> 9
// yellow    -> y  -> 10

int n, tot;
int cnt[100];
int a[100][5], c[100];
int b[100][5];
std::pair<int, int> pr[10005];
std::pair<int, int> pr2[10005];

bool full(int x) { return c[x] == 4; }
bool pure(int x) {
	if (!c[x]) return false;
	int col = b[x][c[x]];
	for (int i = 1; i <= c[x]; ++i) 
		if (b[x][i] != col)
			return false;
	return true;
}

bool same(int x, int y) {
	return b[x][c[x]] == b[y][c[y]];
}

void Trans(int x, int y, int tmp) {
	int &nx = c[x], &ny = c[y], col = b[x][nx];
	if (col == 0) {
		std :: cerr << nx << ' ' << ny << '\n';
		for (int i = 1; i <= nx; ++i)
			std :: cerr << b[x][i] << '\n';
		for (int i = 1; i <= tot; ++i)
			printf("%d %d\n", pr[i].first, pr[i].second);
	}
	if (ny and b[x][nx] != b[y][ny])
		std::cerr << "Trans1", exit(1);
	if (nx == 0 or ny == 4)
		std::cerr << "Trans2" << ' ' << tmp, exit(1);

	while (ny == 0 or b[x][nx] == b[y][ny]) {
		b[y][++ny] = col;
		if (ny > 4)
			std::cerr << tmp, exit(1);
		b[x][nx--] = 0;
	}
	pr[++tot] = std::make_pair(x, y);
}

bool all_pure_worked() {
	for (int i = 1; i <= n; ++i) {
		if (!pure(i)) continue;
		for (int j = 1; j <= n; ++j) {
			if (i == j or !same(i, j)) continue;
			return false;
		}
	}
	return true;
}

bool exist_empty() {
	for (int i = 1; i <= n; ++i)
		if (c[i] == 0) return true;
	return false;
}

bool check(int x, int now) {
	if (x == now) return false;
	if (pure(x) or c[x] == 0) return false;
	return true;
}

int len(int x) {
	int i = c[x], col = b[x][c[x]], res = 0;
	while (i and b[x][i] == col) ++res, --i;
	return res;
}

bool worth_trans(int x, int y) {
	if (!c[x]) return false;
	if (len(x) > 4 - c[y]) return false;
	else return true;
}

bool GG() {
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j) {
			if (i == j) continue;
			if (same(i, j) and worth_trans(i, j)) return false;
		}
	return true;
}

bool finished() {
	for (int i = 1; i <= n; ++i) {
		if (c[i] == 0) continue;
		if (c[i] != 4) return false;
		int col = b[i][1];
		for (int j = 1; j <= 4; ++j)
			if (b[i][j] != col) return false;
	}
	return true;
}

bool exec() {
	memcpy(b, a, sizeof a);
	memset(c, 0, sizeof c);
	for (int j = 1; j <= n - 2; ++j) c[j] = 4;
	tot = 0;

	while (!finished()) {
		while (!all_pure_worked()) {
			for (int i = 1; i <= n; ++i) {
				if (!pure(i)) continue;
				for (int j = 1; j <= n; ++j) {
					if (i == j or !same(i, j)) continue;
					if (!c[j]) continue;
					Trans(j, i, 1);
				}
			}
		}

		if (finished()) return true;

		if (exist_empty()) {
			for (int i = 1; i <= n; ++i)
				if (c[i] == 0) {
					int x = rand() % n + 1;
					while (!check(x, i)) x = rand() % n + 1;
					Trans(x, i, 2);
				}
			continue;
		}

		if (GG()) return false;
		int x = rand() % n + 1, y = rand() % n + 1;
		while (x == y or !same(x, y) or !worth_trans(x, y))
			x = rand() % n + 1, y = rand() % n + 1;
		Trans(x, y, 3);
	}
	return true;
}

int main() {
	srand(time(0));
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);

	std::cin >> n;

	for (int i = 1; i <= n - 2; ++i) {
		for (int j = 4; j; --j) {
			std::string s;
			std :: cin >> s;
			if (s == "b") a[i][j] = 1;
			else if (s == "db") a[i][j] = 2;
			else if (s == "g") a[i][j] = 3;
			else if (s == "dg") a[i][j] = 4;
			else if (s == "pp") a[i][j] = 5;
			else if (s == "pk") a[i][j] = 6;
			else if (s == "gy") a[i][j] = 7;
			else if (s == "r") a[i][j] = 8;
			else if (s == "o") a[i][j] = 9;
			else if (s == "y") a[i][j] = 10;
			else puts("input Error !!!");
			b[i][j] = a[i][j];
			++cnt[b[i][j]];
		}
		c[i] = 4;
	}

	for (int i = 1; i <= n - 2; ++i)
		if (cnt[i] != 4) std::cerr << "cnt", exit(1);

	int min_tot = 0x3f3f3f3f;
	for (int i = 1; i <= 10000; ++i) {
		if (!exec()) continue;
//		printf("%d\n", tot);
		if (tot < min_tot) {
			min_tot = tot;
			memcpy(pr2, pr, sizeof pr);
		}
	}

	puts("Get!!");
	for (int i = 1; i <= min_tot; ++i)
		printf("%d %d\n", pr2[i].first, pr2[i].second);
	return 0;
}
