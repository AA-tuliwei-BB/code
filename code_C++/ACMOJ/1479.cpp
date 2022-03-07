/**********************************************************
  > File Name: 1479.cpp
  > Author: TALBW
  > Created Time: Tue 01 Mar 2022 03:51:25 PM CST
 *******************************************************/

#include <iostream>
#include <cstdio>

using namespace std;

int n;
char s[10000005];
int ne[10000005];

int main() {
	scanf("%d%s", &n, s + 1);
	ne[0] = -1;
	for (int i = 2; i <= n; ++i)
		for (int j = ne[i - 1]; ~j; j = ne[j])
			if (s[i] == s[j + 1]) {
				ne[i] = j + 1;
				break;
			}

	cout << n - ne[n] << endl;
	return 0;
}
