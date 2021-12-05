#include <iostream>
#include "module1.h"
#include "module2.h"

using namespace std;

void showOptions() {
	printf("欢迎使用股票分析系统：\n");
	printf("1--输入股票价格序列\n");
	printf("2--查询股票价格\n");
	printf("3--输出升序的股票价格序列\n");
	printf("4--输出最大值和最小值的日期\n");
	printf("5--一笔交易的最大利润\n");
	printf("6--多笔交易的最大利润\n");
	printf("7--退出\n");
}

int main()
{
	showOptions();
	while (true) {
		int opt; cin >> opt;
		if (opt == 1) input();
		if (opt == 2) QueryPrice();
		if (opt == 3) QueryAscd();
		if (opt == 4) QueryDate();
		if (opt == 5) MaxInterestA();
		if (opt == 6) MaxInterestB();
		if (opt == 7) return 0;
	}
    return 0;
}
