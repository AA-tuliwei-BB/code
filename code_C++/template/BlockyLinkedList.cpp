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

	void erase(int pos) {
		--pos;
		Block *p = head;
		while (p->next and pos >= p->size) {
			pos -= p->size;
			p = p->next;
		}
		p->erase(pos);
	}

	void Display() {
		for (Block *p = head; p; p = p->next)
			p->Display();
	}
};
// }}}
