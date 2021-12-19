// file: main.cpp
#include <bits/stdc++.h>
#include "professor.h"
#include "birthday.h"
#include "teacher.h"

using namespace std;

int main() {
	int num;
	string name, sex;
	int y, m, d;
	cin >> num >> name >> sex >> y >> m >> d;
	birthday bir(y, m, d);
	teacher tch(num, name, sex);
	professor pfs(tch, bir);
	cin >> y >> m >> d;
	bir = birthday(y, m, d);
	pfs = professor(tch, bir);
	pfs.output();
	return 0;
}
