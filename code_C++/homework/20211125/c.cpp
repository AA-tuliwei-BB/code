#include <bits/stdc++.h>

using namespace std;

int f(int x, int y, int z) {
	if (z == 0) return x * 3 - y * 2;
	if (z & 1) return x * 2 - y + z + f(x + 1, y + 1, z - 1);
	return x + y + z + f(x + 1, y + 1, z >> 1);
}

int main(void) {
    int z; cin >> z;
    cout << f(0, 0, z) << endl;
    return 0;
}
