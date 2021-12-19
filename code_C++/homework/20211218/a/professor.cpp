// file: professor.cpp
#include "professor.h"
#include "birthday.h"
#include "teacher.h"

professor::professor() {}

professor::professor(const teacher &t, const birthday &b) {
	tch = t, bir = b;
}

void professor::output() {
	tch.output();
	bir.output();
	puts("");
}
