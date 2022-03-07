/***********************************************************
  > File Name: T7.cpp
  > Author: TALBW
  > Created Time: Thu 03 Mar 2022 11:33:18 AM CST
 *******************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#define ull unsigned long long

using namespace std;

const int maxn = 1e6;

int n;
char s[maxn + 5];

const ull Base = 233;
ull Pow[maxn + 5];
ull Hash_array[maxn + 5]; // 笑死，就不用KMP

void build_hash() {
	Pow[0] = 1;
	for (int i = 1; i <= n; ++i) {
		Hash_array[i] = Hash_array[i - 1] * Base + s[i];
		Pow[i] = Pow[i - 1] * Base;
	}
}

ull Hash(int l, int r) {
	return  Hash_array[r] - Hash_array[l - 1] * Pow[r - l + 1];
}

int main() {
	scanf("%s", s + 1);
	n = strlen(s + 1);

	build_hash();

	for (int i = 1; i <= n; ++i)
		if (Hash(1, i) == Hash(n - i + 1, n))
			printf("%d\n", i);
	return 0;
}
