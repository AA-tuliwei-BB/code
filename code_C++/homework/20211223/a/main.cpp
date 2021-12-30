/***********************************************************
  > File Name: main.cpp
  > Author: TALBW
  > Created Time: Thu 23 Dec 2021 03:08:52 PM CST
 *******************************************************/

#include <bits/stdc++.h>
#include "shape.h"
#include "circle.h"
#include "rectangle.h"
#include "square.h"

using namespace std;

int main() {
  int cx, cy, cr, rx, ry, rw, rh, sx, sy, ss;
  cin >> cx >> cy >> cr;
  cin >> rx >> ry >> rw >> rh; 
  cin >> sx >> sy >> ss;

  // circle center = (cx, cy), radiuis = r
  Circle c(cx, cy, cr);
  // rectangle top left point = (rx, ry), wide = rw, height = rh
  Rectangle r(rx, ry, rw, rh);
  // square top left point = (sx, sy), length of side = ss
  Square s(sx, sy, ss);

  Shape* shape[3] = {&c, &r, &s};
  for (int i = 0; i < 3; ++i) {
    cout << "Shape " << i << ": Position ";
    shape[i]->show_position();
    cout << " Area " << fixed << setprecision(2) << shape[i]->area();
    cout << " Circum " << fixed << setprecision(2)
		<< shape[i]->circum() << endl;
  }

  return 0;
}
