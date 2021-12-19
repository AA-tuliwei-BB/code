// file: professor.h
#ifndef PROFESSOR_H
#define PROFESSOR_H
#include "birthday.h"
#include "teacher.h"
#include <string>

using namespace std;

class professor {
private:
	teacher tch;
	birthday bir;
public:
	professor(const teacher &tch, const birthday &bir);
	professor();
	void output();
};

#endif
