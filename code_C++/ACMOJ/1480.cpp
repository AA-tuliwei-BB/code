/***********************************************************
  > File Name: T6.cpp
  > Author: TALBW
  > Created Time: Tue 01 Mar 2022 07:13:10 PM CST
 *******************************************************/

#include <iostream>
#include <cstdio>

using namespace std;

// {{{ quick input & output
const int InputBufferSize = 67108864 << 1;//输入缓冲区大小
const int OutputBufferSize = 67108864 << 1;//输出缓冲区大小
 
namespace input
{
    char buffer[InputBufferSize],*s,*eof;
    inline void init()
    {
        s=buffer;
        eof=s+fread(buffer,1,InputBufferSize,stdin);
    }
    inline void read(int &x) {
        x=0;
        while(!isdigit(*s)) ++s;
        while(isdigit(*s)) x=x*10+*s++-'0';
    }
}

namespace output
{
    char buffer[OutputBufferSize];
    char *s=buffer;
    inline void flush() {
        fwrite(buffer,1,s-buffer,stdout);
        s=buffer;
        fflush(stdout);
    }
    inline void print(const char ch) {
        if(s-buffer>OutputBufferSize-2)flush();
        *s++=ch;
    }
    inline void print(int x)
    {
        char buf[25]= {0},*p=buf;
        if(x==0)print('0');
        while(x)*(++p)=x%10,x/=10;
        while(p!=buf)print(char(*(p--)+'0'));
    }
}
using namespace input;
using namespace output;
//}}}

const int maxn = 1e6;

int n, m;
int a[maxn + 5];
int sum[maxn + 5]; // 0
int st[maxn + 5][21]; // 1
int lg[maxn + 5];

inline int Sum0(int i, int j) {
	return (1 << j) - sum[i + (1 << j) - 1] + sum[i - 1];
}
inline int Sum(int i, int j) {
	return sum[i + (1 << j) - 1] - sum[i - 1];
}

void build() {
	for (int i = 2; i <= n; ++i)
		lg[i] = lg[i >> 1] + 1;
	for (int i = 1; i <= n; ++i) {
		sum[i] = sum[i - 1] + a[i];
		st[i][0] = 1;
	}

	for (int j = 0; 1 << j < n; ++j)
		for (int i = 1; i <= n; ++i) {
			if (i + (1 << (j + 1)) - 1 > n)
				continue;
			else {
				st[i][j + 1] = max(Sum0(i, j) + st[i + (1 << j)][j],
						st[i][j] + Sum(i + (1 << j), j));
			}
		}
}

int queryA(int l, int r) {
	int d = r - l + 1, ra = 0, rb = 0;
	for (int i = lg[d]; ~i and d; --i)
		if (d & 1 << i) {
			d ^= 1 << i;
			rb = max(ra + st[l][i], rb + Sum(l, i));
			ra += Sum0(l, i), l += (1 << i);
		}
	return max(ra, rb);
}

int queryB(int l, int r) {
	int s = sum[r] - sum[l - 1];
	if (s == 0 or s == r - l + 1) return 1;
	if (!a[l]) return 2;
	for (int i = lg[r - l + 1]; ~i; --i)
		if (!Sum0(l, i)) l += (1 << i);
	if (sum[r] - sum[l - 1]) return 2;
	return 1;
}

int main() {
	init();
	read(n), read(m);
	for (int i = 1; i <= n; ++i)
		read(a[i]);

	build();

	while (m--) {
		int x, y, z;
		read(x), read(y), read(z);
		if (x == 1) print(queryA(y, z));
		else print(queryB(y, z));
		print('\n');
	}
	flush();
	return 0;
}
