/***********************************************************
  > File Name: mystack.cpp
  > Author: TALBW
  > Created Time: Thu 30 Dec 2021 02:51:20 PM CST
 *******************************************************/

#include <bits/stdc++.h>
#include "mystack.h"

using namespace std;

mystack::mystack(int max_size = 100) {
	size = max_size;
	Data = new int [size];
	Top = Data - 1;
}

bool mystack::push(int x) {
	if (Top - Data + 1 == size) return false;
	return *(++Top) = x, true;
}

bool mystack::pop(int &x) {
	if (Top < Data) return false;
	return x = *(Top--), true;
}

bool mystack::isempty() { return Top < Data; } 
bool mystack::isfull() { return Top - Data + 1 == size; }
