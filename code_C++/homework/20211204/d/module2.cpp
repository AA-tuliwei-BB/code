#include <bits/stdc++.h>
#include "module2.h"

using namespace std;

bool PenIsDown;
bool Map[20][20];

void PenUp() { PenIsDown = false; }
void PenDown() { PenIsDown = true; }

void Draw(int x, int y) {
	assert(x < 20 and y < 20);
	Map[x][y] = true;
}

void Show() {
	for (int i = 0; i < 20; ++i) {
		for (int j = 0; j < 20; ++j)
			putchar(Map[i][j] ? '*' : ' ');
		puts("");
	}
}
