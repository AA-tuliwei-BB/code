#include <bits/stdc++.h>
#include "class.h"

using namespace std;

String::String(char *myStr) {
	this->myLen = strlen(myStr);
	this->myStr = new char [myLen + 1];
	strcpy(this->myStr, myStr);
}

String::String(String &str) {
	myLen = str.myLen;
	myStr = new char [myLen + 1];
	strcpy(myStr, str.myStr);
}

String::~String() { delete[] this->myStr; }

int String::length() { return myLen; }

String String::substr(int start, int n) {
	char *tmp = new char [n + 1];
	memcpy(tmp, myStr + start, n), tmp[n] = 0;
	String res(tmp);
	return res;
}

int String::find_first_of(char c) {
	for (int i = 0; i < myLen; ++i)
		if (myStr[i] == c) return i;
	return -1;
}

void String::add_before(int index, char c) {
	char *tmp = new char [++myLen + 1];
	memcpy(tmp, myStr, index);
	strcpy(tmp + index + 1, myStr + index);
	tmp[index] = c;
	delete[] myStr;
	myStr =tmp;
}

void String::delete_at(int index) {
	char *tmp = new char [--myLen + 1];
	memcpy(tmp, myStr, index);
	strcpy(tmp + index, myStr + index + 1);
	delete[] myStr;
	myStr =tmp;
}

void String::printStr() {
	printf("%s\n", myStr);
}
