/***********************************************************
  > File Name: heap.cpp
  > Author: TALBW
  > Created Time: Tue 22 Mar 2022 04:50:16 PM CST
 *******************************************************/

#ifndef HEAP
#define HEAP

#include <iostream>
#include <cstdio>

template <class T>
class heap {
public:
	T *a;
	int size, max_size;
	heap() { a = NULL, size = max_size = 0; }
	~heap() { delete [] a; }

	bool cmp(T a, T b) { return a < b; } // 默认大根

	heap(const heap &b) {
		size = b.size;
		a = new T [size + 1];
		for (int i = 1; i <= size; ++i)
			a[i] = b.a[i];
	}

	void push(T x) {
		if (size == max_size) {
			max_size = (max_size + 1) * 3 / 2;
			T *tmp = new T [max_size + 1];
			for (int i = 1; i <= size; ++i)
				tmp[i] = a[i];
			delete [] a;
			a = tmp;
		}

		int now = ++size;
		a[now] = x;
		while (now >> 1 and cmp(a[now >> 1], a[now]))
			std::swap(a[now >> 1], a[now]), now >>= 1;
	}

	T top() { return a[1]; }

	void pop() {
		int now = 1;
		a[now] = a[size--];
		while ((now << 1 | 1) <= size)
			if (cmp(a[now], a[now << 1]) or cmp(a[now], a[now << 1 | 1]))
				if (cmp(a[now << 1], a[now << 1 | 1]))
					std::swap(a[now], a[now << 1 | 1]), now = now << 1 | 1;
				else std::swap(a[now], a[now << 1]), now <<= 1;
			else break;
		while ((now << 1) <= size and cmp(a[now], a[now << 1]))
			std::swap(a[now], a[now << 1]), now <<= 1;
	}
};

#endif
