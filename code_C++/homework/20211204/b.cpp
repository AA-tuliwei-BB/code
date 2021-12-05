#include <bits/stdc++.h>

using namespace std;

struct Matrix {
	int a, b, c, d;
	void input() { cin >> a >> b >> c >> d; }
	void output() {
		cout << a << ' ' << b << endl;
		cout << c << ' ' << d << endl;
	}
};

Matrix operator * (Matrix a, Matrix b) {
	Matrix res;
	res.a = a.a * b.a + a.b * b.c;
	res.b = a.a * b.b + a.b * b.d;
	res.c = a.c * b.a + a.d * b.c;
	res.d = a.c * b.b + a.d * b.d;
	return res;
}

int main() {
	Matrix a;
	a.input();
	(a * a).output();
	return 0;
}
