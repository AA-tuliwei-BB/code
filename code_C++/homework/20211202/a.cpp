#include <iostream>
using namespace std;

struct electronicClock {
	int hour, minute, second;
	void setTime(int h, int m, int s) {
        hour = h, minute = m, second = s;
    }
    void increase() {
		if (second != 59) return ++second, void();
		second = 0;
		if (minute != 59) return ++minute, void();
		minute = 0;
		if (hour != 23) ++hour;
		else hour = 0;
    }
    void showTime() {
		printf("%02d:%02d:%02d\n", hour, minute, second);
    }
};

int main(){
	electronicClock clk;
    
    for (int t=0; t<2; t++) {
    	int h, m, s;
        cin >> h >> m >> s;
        clk.setTime(h, m, s);
        clk.showTime();
        clk.increase();
        clk.showTime();
    }
	
	return 0;
}

