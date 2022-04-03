template <class T, int maxn>
class stTable {
	T st[maxn + 5][21];
	int lg[maxn + 5];
#define max(x,y) ((x) < (y) ? (y) : (x))
public:
	void build(int* a, int n) {
		for (int i = 2; i <= n; ++i)
			lg[i] = lg[i >> 1] + 1;
		for (int i = 1; i <= n; ++i) st[i][0] = a[i];

		for (int j = 0; j < lg[n]; ++j)
			for (int i = 1; i <= n; ++i)
				if (i + (1 << j) > n) st[i][j + 1] = st[i][j];
				else st[i][j + 1] = max(st[i][j], st[i + (1 << j)][j]);
	}

	int query(int l, int r) {
		int Log = lg[r - l];
		return max(st[l][Log], st[r - (1 << Log) + 1][Log]);
	}
#undef max
};
