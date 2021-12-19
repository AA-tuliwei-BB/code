#include <iostream>
#include "class.h"

using namespace std;

wall::wall() {}
void wall::set(int nl, int nw) { length = nl, width = nw; }
int wall::get_area() { return length * width; }
int wall::get_extra() { return extra_data++; }
