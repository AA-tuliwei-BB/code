/***********************************************************
  > File Name: account.h
  > Author: TALBW
  > Created Time: Thu 30 Dec 2021 02:21:52 PM CST
 *******************************************************/

#ifndef ACCOUNT_H
#define ACCOUNT_H

class SavingAccount {
private:
	int id;
	static int NextIndex;
	float MonthRate = 0.05;
	long double num = 0;
public:
	SavingAccount();
	SavingAccount(int);
	void calculate();
	void display();
	void changerate(float);
};

#endif
