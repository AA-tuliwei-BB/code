#include <bits/stdc++.h>

using namespace std;

struct comp {
	int a, b;
	comp (int _a = 0, int _b = 0) { a = _a, b = _b; }
	comp operator + (comp y) { return comp(a + y.a, b + y.b); }
	comp operator * (comp y) {
		int _a = a * y.a - b * y.b;
		int _b = b * y.a + a * y.b;
		return comp(_a, _b);
	}
	void output(bool ln = true) {
		printf("%d", a);
		if (b >= 0) printf("+%di", b);
		else printf("%di", b);
		if (ln) putchar('\n');
	}
};

int main() {
	comp x, y;
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	x = comp(a, b), y = comp(c, d);
	printf("x = "), x.output();
	printf("y = "), y.output();
	x = x + y, printf("x += y; x = "), x.output();
	y = x * y, printf("y *= x; y = "), y.output();
	printf("x + y = "), (x + y).output();
	printf("y * x = "), (x * y).output();
	printf("x = "), x.output();
	printf("y = "), y.output();
	return 0;
}
