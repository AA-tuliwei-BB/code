#include <bits/stdc++.h>
#include "module1.h"
#include "module2.h"

using namespace std;

void showOption(){
    cout<<"欢迎来到Logo绘制系统："<<endl;
    cout<<"1--笔向上"<<endl;
    cout<<"2--笔向下"<<endl;
    cout<<"3--左转"<<endl;
    cout<<"4--右转"<<endl;
    cout<<"5 n--前进n格（n为正整数）"<<endl;
    cout<<"6--打印20*20数组"<<endl;
    cout<<"9--数据结束（标记）"<<endl;
}

int main() {
	showOption();
	while (true) {
		int opt; cin >> opt;
		if (opt == 1) PenUp();
		if (opt == 2) PenDown();
		if (opt == 3) TurnLeft();
		if (opt == 4) TurnRight();
		if (opt == 5) {
			int tmp; cin >> tmp;
			GoForward(tmp);
		}
		if (opt == 6) Show();
		if (opt == 9) return 0;
	}
    return 0;
}

