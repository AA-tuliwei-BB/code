#include <iostream>
#include "class.h"

using namespace std;

int main(){
    char str[105];
    cin.getline(str, 101);
    String s(str);
    char op[2];
    while (cin >> op && op[0] != '@') {
        if (op[0] == '0') {
            cout << s.length() << endl;
        } else if (op[0] == '1') {
            int st, ed;
            cin >> st >> ed;
            s.substr(st, ed-st+1).printStr(); 
        } else if (op[0] == '2') {
            char c;
            cin >> c;
            cout << s.find_first_of(c) << endl;
        } else if (op[0] == '3') {
            int index;
            char c;
            cin >> index >> c;
            s.add_before(index, c);
        } else if (op[0] == '4') {
            int index;
            cin >> index;
            s.delete_at(index);
        } else {
            s.printStr();
        }
    }

    return 0;
}
