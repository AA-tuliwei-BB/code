#include <bits/stdc++.h>
#include "module1.h"
#include "module2.h"

// 移动模块

struct Position {
	int x, y;
	Position (int _x = 0, int _y = 0) { x = _x, y = _y; }
	bool operator == (Position b) { return x == b.x and y == b.y; }
	void operator += (Position b) { x += b.x; y += b.y; }
};

typedef Position Direction;

static Position pnow;
static Direction left(0, -1), right(0, 1);
static Direction up(-1, 0), down(1, 0), dnow = down;

void GoForward(int x) {
	while (x--) {
		pnow += dnow;
		if (PenIsDown)
			Draw(pnow.x, pnow.y);
	}
}

void TurnLeft() {
	if (dnow == left) dnow = down;
	else if (dnow == down) dnow = right;
	else if (dnow == right) dnow = up;
	else if (dnow == up) dnow = left;
}

void TurnRight() {
	if (dnow == down) dnow = left;
	else if (dnow == left) dnow = up;
	else if (dnow == up) dnow = right;
	else if (dnow == right) dnow = down;
}
