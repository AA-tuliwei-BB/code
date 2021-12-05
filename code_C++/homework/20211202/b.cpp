#include <bits/stdc++.h>

using namespace std;

struct hero {
	string name, sex;
	int age;
	bool operator < (hero b) {
		return age < b.age;
	}
};

const int n = 5;
hero h[n + 1];

int main() {
	for (int i = 1; i <= n; ++i) {
		string name, sex;
		int age;
		cin >> name >> age >> sex;
		h[i] = (hero) { name, sex, age };
	}

	sort(h + 1, h + n + 1);
	
	for (int i = 1; i <= n; ++i)
		cout << h[i].name << ' ' << h[i].age << ' ' << h[i].sex << endl;
	return 0;
}
