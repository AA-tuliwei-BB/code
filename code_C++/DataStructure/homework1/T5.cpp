/***********************************************************
  > File Name: T5.cpp
  > Author: TALBW
  > Created Time: Thu 03 Mar 2022 11:02:44 AM CST
 *******************************************************/

#include <iostream>
#include <cstdio>

using namespace std;

// {{{ BlockyLinkedList
template <int MaxSize = 400>
class BlockyLinkedList {
	struct Node {
		Node *next;
		int val;
		Node(int v = 0, Node *p = NULL) { val = v, next = p; }
	};
	struct Block {
		int size;
		Block *next;
		Node *head;
		Block(Block *p = NULL) { size = 0, next = p, head = new Node; }
		~Block() {
			for (Node *p = head, *q; p->next; p = q) {
				q = p->next;
				delete p;
			}
		}

		void split() {
			int LSize = MaxSize >> 1, RSize = MaxSize - LSize;
			int tmp = LSize; Node *p = head;
			while (tmp--) p = p->next;
			Block *New = new Block(this->next);
			this->next = New, New->head->next = p->next, p->next = NULL;
			this->size = LSize, New->size = RSize;
		}

		void insert(int val) {
			Node *p = head;
			while (p->next) p = p->next;
			p->next = new Node;
			p->next->val = val;
			++size;
			if (size == MaxSize) this->split();
		}

		void insert(int pos, int val) {
			Node *p = head;
			while (pos-- and p->next) p = p->next;
			if (~pos) return void();
			Node *New = new Node(val, p->next);
			p->next = New;
			++size;
			if (size == MaxSize) this->split();
		}

		void erase(int pos) {
			Node *p = head;
			while (pos-- and p->next) p = p->next;
			if (~pos) exit(1);
			Node *Next = p->next->next;
			delete p->next;
			p->next = Next;
			--size;
		}

		void Display() {
			for (Node *p = head->next; p; p = p->next)
				printf("%d ", p->val);
		}
	};

private:
	Block *head;
public:
	int size;
	BlockyLinkedList() { head = new Block; }
	~BlockyLinkedList() {
		for (Block *p = head, *q; p->next; p = q) {
			q = p->next;
			delete p;
		}
	}

	void insert(int val) {
		Block *p = head;
		while (p->next) p = p->next;
		p->insert(val);
		++size;
	}

	void insert(int pos, int val) {
		Block *p = head;
		while (p->next and pos > p->size) {
			pos -= p->size;
			p = p->next;
		}
		p->insert(pos, val);
		++size;
	}

	void erase(int pos) {
		--pos;
		Block *p = head;
		while (p->next and pos >= p->size) {
			pos -= p->size;
			p = p->next;
		}
		p->erase(pos);
		--size;
	}

	void Display() {
		for (Block *p = head; p; p = p->next)
			p->Display();
	}
};
// }}}

BlockyLinkedList<400> list;

int n, m;

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		list.insert(i);

	int now = 1, dir = 1;
	for (int aVarOfNoUse = 1; aVarOfNoUse < n; ++aVarOfNoUse) {
		int tmp = (m - 1) % ((list.size - 1) << 1) + 1, size = list.size;
		if (dir == 1) {
			now += tmp - 1;
			if (now > size) {
				now = size * 2 - now, dir = 0;
				if (now <= 0) now = 2 - now, dir = 1;
			}
		} else {
			now -= tmp - 1;
			if (now <= 0) {
				now = 2 - now, dir = 1;
				if (now > size) now = size * 2 - now, dir = 0;
			}
		}
		list.erase(now);
//		list.Display(), puts("");
		if (now == size) { now = size - 1; continue; }
		if (now == 1) continue;
		if (dir == 0) --now;
	}

	list.Display();
	putchar('\n');
	return 0;
}
