#include <iostream>
#include <cstring>
using namespace std;

char * reply(const char * sentence) {
	char tmp;
	char * res;
	for (int i = 0; sentence[i]; ++i)
		tmp = sentence[i];
	if (tmp == '!') res = "Really?!";
	else if (tmp == '?') res = "Emmmm…";
	else res = "Cool.";
	return res;
}

int main(void) {
	char str[1005];
    cin.getline(str, 1000);
    char * res = reply(str);
    if (res) cout << res << endl;
    delete [] res;
    return 0;
}
