#ifndef CLASS_H
#define CLASS_H

class Matrix {
private:
	int n, m;
	double a[1001][1001];
public:
	void Initialization();
	void Transpose();
	void Determinant();
};

#endif
