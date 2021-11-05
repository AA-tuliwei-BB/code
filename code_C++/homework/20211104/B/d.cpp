#include <bits/stdc++.h>

using namespace std;

int Magic(int m){
	for (int i = 100; i <= 999; ++i)
		if (222 * ((i / 100) + i / 10 % 10 + i % 10) - i == m)
			return i;
   return -1;
}

int main()
{
    int t,m;
    cin >> t;
    while(t--){
        cin >> m;
        int res = Magic(m);
        if(res == -1) {
            cout << "The sum you calculated is wrong!\n";
        } else {
            cout << "The number is " << res << endl;
        }
    }
}
