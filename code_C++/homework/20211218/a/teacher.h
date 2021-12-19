// file: teacher.h
#ifndef TEACHER_H
#define TEACHER_H
#include <string>
using namespace std;

class teacher {
private:
	int num;
	string name, sex;
public:
	teacher();
	teacher(int nu, string na, string s);
	void output();
};

#endif
