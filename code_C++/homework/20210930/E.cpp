#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

ld xa, xb, ya, yb, ra, rb;
ld ymin, ymax, xmin, xmax;

ld dist(ld xa, ld ya, ld xb, ld yb) {
	return sqrt((xa - xb) * (xa - xb) + (ya - yb) * (ya - yb));
}

ld Rand() {
	return 1.0L * rand() / RAND_MAX;
}

bool In(ld x, ld y) {
	return (dist(x, y, xa, ya) <= ra or dist(x, y, xb, yb) <= rb);
}

int main() {
	cin >> xa >> ya >> ra >> xb >> yb >> rb;
	ymin = min(ya - ra, yb - rb);
	ymax = max(ya + ra, yb + rb);
	xmin = min(xa - ra, xb - rb);
	xmax = max(xa + ra, xb + rb);

	long double S1 = (ymax - ymin) * (xmax - xmin);

	int cnt = 0;
	for (int i = 1; i <= 10000; ++i) {
		for (int j = 1; j <= 10000; ++j) {
			ld x = xmin + (ld) i / 10000 * (xmax - xmin);
			ld y = ymin + (ld) j / 10000 * (ymax - ymin);
			if (In(x, y)) ++cnt;
		}
	}

	printf("%.3Lf\n", S1 * cnt / 100000000);
	return 0;
}
