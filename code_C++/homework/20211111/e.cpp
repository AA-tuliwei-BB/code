#include <bits/stdc++.h>

using namespace std;

int a[] = { 8, 7, 3, 4, 9, 6, 2 };

void encrypt(char * s) {
	int n = strlen(s);
	for (int i = 0, j = 0; i < n; ++i, j = j == 6 ? 0 : j + 1)
		s[i] = (s[i] + a[j]) > 'z' ? (s[i] + a[j] - 91) : s[i] + a[j];
}

void decrypt(char * s) {
	int n = strlen(s);
	for (int i = 0, j = 0; i < n; ++i, j = j == 6 ? 0 : j + 1)
		s[i] = (s[i] - a[j]) < 32 ? (s[i] - a[j] + 91) : s[i] - a[j];
}

int main(void) {
	char s[35];
    cin.getline(s, 30);
    encrypt(s);
    cout << s << endl;
    decrypt(s);
    cout << s << endl;
	return 0;
}
