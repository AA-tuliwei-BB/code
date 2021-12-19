// file: birthday.cpp
#include "professor.h"
#include "birthday.h"
#include "teacher.h"

birthday::birthday(int y, int m, int d) { year = y, month = m, day = d; }
birthday::birthday() { year = month = day = 0; }
void birthday::output() { printf("birthday:%d/%d/%d", year, month, day); }
