#include <bits/stdc++.h>
#include "class.h"

using namespace std;

Roman a;

int main() {
	string tmp;
	cin >> tmp;
	while (tmp[0] != '@') {
		if (isdigit(tmp[0])) {
			a.SetN(tmp);
			a.ShowR();
		} else {
			a.SetR(tmp);
			a.ShowN();
		}
		cin >> tmp;
	}
	return 0;
}
