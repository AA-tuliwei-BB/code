#include <bits/stdc++.h>
#include "class.h"

using namespace std;

Clock Time(Clock c1, Clock c2){
	if (c1 < c2) swap(c1, c2);
	return c1 - c2;
}

int main(){
	Clock a, b;
	a.input(), b.input();
	Clock c = Time(a, b);
	c.output();
    return 0;
}
