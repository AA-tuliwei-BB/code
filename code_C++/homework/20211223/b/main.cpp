/***********************************************************
  > File Name: main.cpp
  > Author: TALBW
  > Created Time: Thu 23 Dec 2021 04:08:32 PM CST
 *******************************************************/

#include <bits/stdc++.h>
#include "LLIComplex.h"
#include "LongLongInt.h"

int main()
{
    longlongintcomplex r1("0","99"), r2("00","10001"),r3;
    cout<<"r1="<<r1<<endl;
    cout<<"r2="<<r2<<endl;
    r3=r1+r2;
    cout<<"r3=r1+r2="<<r3<<endl;
    return 0;
}
