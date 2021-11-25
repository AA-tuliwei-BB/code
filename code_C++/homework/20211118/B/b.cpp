#include <bits/stdc++.h>

using namespace std;

void deletechar(char* str1, const char* str2) {
	static bool mp[300] = {0};
	for (int n = strlen(str2), i = 0; i < n; ++i)
		mp[str2[i]] = true;
	for (int i = 0, t = 0;; ++i) {
		if (mp[str1[i]]) ++t;
		else str1[i - t] = str1[i];
		if (!str1[i]) return void();
	}
}

int main() {
	char str1[85], str2[85];
	cin.getline(str1, 80);
    cin.getline(str2, 80);
    
	deletechar(str1, str2);

    cout<<str1<<endl;
	return 0;
}
