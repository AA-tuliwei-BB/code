/***********************************************************
  > File Name: account.cpp
  > Author: TALBW
  > Created Time: Thu 30 Dec 2021 02:21:49 PM CST
 *******************************************************/

#include <bits/stdc++.h>
#include "account.h"

using namespace std;

int SavingAccount::NextIndex = 1;

SavingAccount::SavingAccount() { id = NextIndex++; }
SavingAccount::SavingAccount(int x) { id = NextIndex++, num = x; }
void SavingAccount::calculate() { num = num * (1 + MonthRate); }
void SavingAccount::changerate(float x) { MonthRate = x; }
void SavingAccount::display() {
	printf("%d %.2Lf %.2f\n", id, num, MonthRate);
}

