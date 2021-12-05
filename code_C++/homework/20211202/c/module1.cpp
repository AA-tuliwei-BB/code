#include <bits/stdc++.h>
#include "module1.h"

using namespace std;

/*
	实现功能
	input() : 读入
	QueryPrice() : 查询价格
	QueryAscd() : 查询价格(升序)
	QueryDate() : 查询最小、最大价格的出现最小日期
*/

vector<int> p; // 存放价格数据

void input() {
	int tmp;
	while (true) {
		cin >> tmp;
		if (tmp == -1) return void();
		p.push_back(tmp);
	}
}

void QueryPrice() {
	for (int pri : p)
		cout << pri << ' ';
	cout << endl;
}

void QueryAscd() {
	vector<int> tmp = p;
	sort(tmp.begin(), tmp.end());
	for (int pri : tmp)
		cout << pri << ' ';
	cout << endl;
}

void QueryDate() {
	int Min = 0x3f3f3f3f, Max = 0, minp = 0, maxp = 0;
	for (int i = 0; i < p.size(); ++i) {
		if (p[i] < Min) Min = p[i], minp = i;
		if (p[i] > Max) Max = p[i], maxp = i;
	}
	cout << minp << ' ' << maxp << endl;
}
