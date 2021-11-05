#include <bits/stdc++.h>

using namespace std;

int n, cnta, cntn, cnt;
char c;

int main() {
	cin >> n;
	while (cin >> c) {
		if (isalpha(c)) ++cnta;
		else if (isdigit(c)) ++cntn;
		else ++cnt;
	}

	printf("英文字母：%d\n", cnta);
    printf("数字：%d\n", cntn);
    printf("其他字符：%d\n", cnt);
	return 0;
}
