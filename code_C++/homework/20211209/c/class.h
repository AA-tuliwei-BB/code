#ifndef CLASS_H
#define CLASS_H
#include <string>
using namespace std;

class Roman {
public:
	int num;
	void SetN(string s);
	void SetR(string s);
	void ShowN();
	void ShowR();
};

#endif
