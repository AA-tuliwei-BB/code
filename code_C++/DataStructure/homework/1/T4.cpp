/***********************************************************
  > File Name: T4.cpp
  > Author: TALBW
  > Created Time: Tue 01 Mar 2022 04:33:33 PM CST
 *******************************************************/

#include <iostream>
#include <cstdio>

using namespace std;

// {{{ quick input & output
const int InputBufferSize = 67108864;//输入缓冲区大小
const int OutputBufferSize = 67108864;//输出缓冲区大小
 
namespace input
{
    char buffer[InputBufferSize],*s,*eof;
    inline void init()
    {
        s=buffer;
        eof=s+fread(buffer,1,InputBufferSize,stdin);
    }
    inline void read(int &x) {
        x=0;
        while(!isdigit(*s)) ++s;
        while(isdigit(*s)) x=x*10+*s++-'0';
    }
}

namespace output
{
    char buffer[OutputBufferSize];
    char *s=buffer;
    inline void flush() {
        fwrite(buffer,1,s-buffer,stdout);
        s=buffer;
        fflush(stdout);
    }
    inline void print(const char ch) {
        if(s-buffer>OutputBufferSize-2)flush();
        *s++=ch;
    }
    inline void print(int x)
    {
        char buf[25]= {0},*p=buf;
        if(x==0)print('0');
        while(x)*(++p)=x%10,x/=10;
        while(p!=buf)print(char(*(p--)+'0'));
    }
}
using namespace input;
using namespace output;
// }}}

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

		void Delete(int pos) {
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
				print(p->val), print(' ');
		}
	};

private:
	Block *head;
public:
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
	}

	void insert(int pos, int val) {
		Block *p = head;
		while (p->next and pos > p->size) {
			pos -= p->size;
			p = p->next;
		}
		p->insert(pos, val);
	}

	void Delete(int pos) {
		--pos;
		Block *p = head;
		while (p->next and pos >= p->size) {
			pos -= p->size;
			p = p->next;
		}
		p->Delete(pos);
	}

	void Display() {
		for (Block *p = head; p; p = p->next)
			p->Display();
		print('\n');
	}
};
// }}}

BlockyLinkedList<600> list;

int n, m;

int main() {
	init();
	read(n), read(m);
	for (int i = 1, x; i <= n; ++i)
		read(x), list.insert(x);

	while (m--) {
		int op, x;
		read(op), read(x);
		if (op == 1) {
			int y; read(y);
			list.insert(x, y);
		} else list.Delete(x);
	}

	list.Display();
	flush();
	return 0;
}
