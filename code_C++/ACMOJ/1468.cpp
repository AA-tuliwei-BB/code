/***********************************************************
  > File Name: 1468.cpp
  > Author: TALBW
  > Created Time: Sun 20 Feb 2022 07:27:20 PM CST
 *******************************************************/

#include <cstdio>
#include <iostream>
#pragma GCC optimize("Ofast")

using namespace std;

template<class T>
struct Node {
	Node *next, *pre;
	T *to;
	Node() { next = pre = NULL, to = NULL; }
};

template<class T>
class LinkedList {
public:
	int __size; 
	Node<T> *head, *tail;
	LinkedList() {
		head = new Node<T>, tail = new Node<T>;
		head->next = tail, tail->pre = head, __size = 0;
	}
	LinkedList(const LinkedList<T> &b) {
		head = new Node<T>, tail = new Node<T>;
		head->next = tail, tail->pre = head, __size = 0;
		for (Node<T> *p = b.head->next; p->next; p = p->next)
			this->pushBack(*(p->to));
	}
	virtual ~LinkedList() {
		for (Node<T> *p = head->next; p->next; ) {
			if (p->to) delete p->to;
			Node<T> *q = p->next;
			delete p;
			p = q;
		}
		delete head;
		delete tail;
	}

	void pushFront(T x) {
		Node<T> *tmp = new Node<T>, *q = head->next;
		q->pre = head->next = tmp;
		tmp->pre = head, tmp->next = q;
		tmp->to = new T, *(tmp->to) = x;
		++__size;
	}

	void pushBack(T x) {
		Node<T> *tmp = new Node<T>, *q = tail->pre;
		q->next = tail->pre = tmp;
		tmp->next = tail, tmp->pre = q;
		tmp->to = new T, *(tmp->to) = x;
		++__size;
	}

	T popFront() {
		if (!__size) return T();
		--__size;
		Node<T> *p = head->next;
		head->next = p->next;
		p->next->pre = head;
		T res = *(p->to);
		delete p->to; delete p;
		return res;
	}

	T popBack() {
		if (!__size) return T();
		--__size;
		Node<T> *p = tail->pre;
		tail->pre = p->pre;
		p->pre->next = tail;
		T res = *(p->to);
		delete p->to; delete p;
		return res;
	}

	void print() {
		for (Node<T> *p = head->next; p->next; p = p->next) {
			if (p->next->next) cout << *(p->to) << ' ';
			else cout << *(p->to) << endl;
		}
	}

	int size() { return __size; }
	virtual const char* name() { return "List"; }
	virtual T peak() { return T(); }
	virtual T pop() { return T(); }
	virtual void push(T val) {}
};

template<class T>
class Stack: public LinkedList<T> {
public:
	const char* name() { return "Stack"; }
	void push(T val) { this->pushBack(val); }
	T pop() { return this->popBack(); }
	T peak() { return *(this->tail->pre->to); }
};

template<class T>
class Queue: public LinkedList<T> {
public:
	const char* name() { return "Queue"; }
	void push(T val) { this->pushBack(val); }
	T pop() { return this->popFront(); }
	T peak() { return *(this->head->next->to); }
};

/*
int main() {
    LinkedList<double> * list = new LinkedList<double>;
    LinkedList<double> * stack = new Stack<double>;
    LinkedList<double> * queue = new Queue<double>;

    cout << "LinkedList" << endl;
    list->pushFront(1);
    list->pushBack(2);
    list->pushBack(3);
    list->pushFront(4);
    list->print();
    list->popFront();
    list->popBack();
    list->print();
    cout << list->size() << endl;

    cout << stack->name() << endl;
    stack->push(1);
    stack->push(2);
    stack->push(3);
    stack->push(4);
    cout << stack->peak() << endl;
    stack->pop();
    cout << stack->pop() << endl;
    cout << stack->peak() << endl;

    cout << queue->name() << endl;
    queue->push(1);
    queue->push(2);
    queue->push(3);
    queue->push(4);
    cout << queue->peak() << endl;
    queue->pop();
    cout << queue->pop() << endl;
    cout << queue->peak() << endl;

    delete list;
    delete stack;
    delete queue;

    return 0;
}*/
