// file: teacher.cpp
#include "professor.h"
#include "birthday.h"
#include "teacher.h"
#include <bits/stdc++.h>

using namespace std;

teacher::teacher() {}
teacher::teacher(int nu, string na, string s) {
	num = nu;
	name = na;
	sex = s;
}

void teacher::output() {
	printf("num:%d\n", num);
	printf("name:%s\n", name.c_str());
	printf("sex:%s\n", sex.c_str());
}
