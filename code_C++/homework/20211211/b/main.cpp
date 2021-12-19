#include<iostream>
#include "class.h"

using namespace std;

int wall::extra_data = 1;
int main(){
    //7 objects are instantiated, including an array
    wall small, medium, large, group[4];

    /******** Your code start here**********/

    cin >> small >> medium >> large;
    cin >> group[0] >> group[1] >> group[2] >> group[3];

    /********** end your code *****************/
    cout<<"Area of the small wall is "<<small.get_area()<<"\n";

    cout<<"Area of the medium wall is "<<medium.get_area()<<"\n";

    cout<<"Area of the large wall is "<<large.get_area()<<"\n";


    for(int index=0; index<4; index++)
    {
        cout<<"An array of wall area "<<index<<" is "<<group[index].get_area()<<"\n";
    }


    cout<<"Extra data value is "<<small.get_extra()<<"\n";
    cout<<"New Extra data value is "<<medium.get_extra()<<"\n";
    cout<<"New Extra data value is "<<large.get_extra()<<"\n";
    cout<<"New Extra data value is "<<group[0].get_extra()<<"\n";
    cout<<"New Extra data value is "<<group[3].get_extra()<<"\n";
    return 0;
}
