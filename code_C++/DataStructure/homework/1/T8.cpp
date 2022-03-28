/***********************************************************
  > File Name: T8.cpp
  > Author: TALBW
  > Created Time: Tue 08 Mar 2022 04:43:02 PM CST
 *******************************************************/

#include <iostream>
#include <cstdio>
#define inf 0x3f3f3f3f

using namespace std;

const int maxn = 2e5;

// {{{ quick input & output | init() before use and flush in the end
const int InputBufferSize = 67108864 << 1;//输入缓冲区大小
const int OutputBufferSize = 67108864 << 1;//输出缓冲区大小
 
namespace Input
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

	int input() {
		int x; bool flag = false;
		while (!isdigit(*s)) { if (*s == '-') flag = true; ++s; }
		for (x = *s++ ^ 48; isdigit(*s); x = x * 10 + (*s++ ^ 48));
		return flag ? -x : x;
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
using namespace Input;
using namespace output;
//}}}

template <class T, int maxn, int (max)(T a, T b)>
class stTable {
	T st[maxn + 5][21];
	int lg[maxn + 5];
public:
	void build(int* a, int n) {
		for (int i = 2; i <= n; ++i)
			lg[i] = lg[i >> 1] + 1;
		for (int i = 1; i <= n; ++i) st[i][0] = a[i];

		for (int j = 0; j < lg[n]; ++j)
			for (int i = 1; i <= n; ++i)
				if (i + (1 << j) > n) st[i][j + 1] = st[i][j];
				else st[i][j + 1] = max(st[i][j], st[i + (1 << j)][j]);
	}

	int query(int l, int r) {
		int Log = lg[r - l];
		return max(st[l][Log], st[r - (1 << Log) + 1][Log]);
	}
#undef max
};

int Max(int x, int y) { return x < y ? y : x; }
int Min(int x, int y) { return x < y ? x : y; }

stTable<int, maxn, Max> sta;
stTable<int, maxn, Min> stb;
int n, m;
int a[maxn + 5], b[maxn + 5], c[maxn + 5];
int sum[maxn + 5];

int main() {
	init();
	n = input(), m = input();
	for (int i = 1; i <= n; ++i)
		a[i] = input();
	for (int i = 1; i <= n; ++i) {
		b[i] = input();
		c[i] = b[i] - a[i];
		sum[i] = sum[i - 1] + c[i];
	}

	sta.build(sum, n);
	stb.build(sum, n);

	while (m--) {
		int l = input(), r = input();
		if (sum[r] - sum[l - 1]) { puts("-1"); continue; }
		if (stb.query(l, r) < sum[l - 1]) { puts("-1"); continue; }
		printf("%d\n", sta.query(l, r) - sum[l - 1]);
	}
	flush();
	return 0;
}
