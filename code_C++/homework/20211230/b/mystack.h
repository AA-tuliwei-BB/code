/***********************************************************
  > File Name: mystack.h
  > Author: TALBW
  > Created Time: Thu 30 Dec 2021 02:51:15 PM CST
 *******************************************************/

#ifndef MYSTACK_H
#define MYSTACK_H

class mystack {
private:
	int size;
	int *Data, *Top;
public:
	mystack(int);
	bool push(int);
	bool pop(int&);
	bool isempty();
	bool isfull();
};

#endif
