#ifndef SJTU_LIST_HPP
#define SJTU_LIST_HPP

#include "exceptions.hpp"
#include "algorithm.hpp"

#include <climits>
#include <cstddef>

namespace sjtu {
/**
 * a data container like std::list
 * allocate random memory addresses for data and they are doubly-linked in a list.
 */

template<typename T> bool cmp(const T &a, const T &b) { return *a < *b; }

template<typename T>
class list {

	// {{{ node
protected:
    class node {
    public:
		T *point;
		node *left, *right;
		node() { left = right = NULL, point = NULL; }
		node(const T & val) {
			left = right = NULL;
			point = new T(val);
		}
		~node() { if (point != NULL) delete point; }
    };
	// }}}

	// {{{ protected
protected:
	node *head, *tail;

    node *insert(node *pos, node *cur) {
		if (pos == head) exit(1);
		node *pre = pos->left;
		pre->right = cur, cur->left = pre;
		cur->right = pos, pos->left = cur;
		return cur;
	}

    node *erase(node *pos) {
		if (pos == head or pos == tail) exit(2);
		pos->left->right = pos->right;
		pos->right->left = pos->left;
		node *res = pos->right;
		delete pos;
		return res;
	}
	// }}}

public:
	class const_iterator;

	// {{{ iterator
    class iterator {
		friend list;
    private:
		list<T> *List;
		node *p;

    public:
		// {{{ construct
		iterator() { List = NULL, p = NULL; }
		iterator(list<T> *__List, node *__p) {
			List = __List;
			p = __p;
		}

		iterator(const iterator & other) {
			List = other.List;
			p = other.p;
		}
		// }}}

		// {{{ ++ and -- 
		// iter++
        iterator operator++(int) {
			if (p->right == NULL) throw invalid_iterator();
			iterator res = *this;
			p = p->right;
			return res;
		}
        // ++iter
        iterator & operator++() {
			if (p->right == NULL) throw invalid_iterator();
			p = p->right;
			return *this;
		}
        // iter--
        iterator operator--(int) {
			if (p->left == List->head) throw invalid_iterator();
			iterator res = *this;
			p = p->left;
			return res;
		}
        // --iter
        iterator & operator--() {
			if (p->left == List->head) throw invalid_iterator();
			p = p->left;
			return *this;
		}
		// }}}

		// {{{ *, ->, == and !=
        T & operator *() const {
			if (p->point == NULL) throw invalid_iterator();
			return *p->point;
		}

        T * operator ->() const noexcept { return p->point; }

        bool operator==(const iterator &rhs) const {
			return this->p == rhs.p;
		}
        bool operator==(const const_iterator &rhs) const {
			return this->p == rhs.p;
		}
        bool operator!=(const iterator &rhs) const {
			return this->p != rhs.p;
		}
        bool operator!=(const const_iterator &rhs) const {
			return this->p != rhs.p;
		}
		// }}}
    };
	// }}}

	// {{{ const_iterator
	class const_iterator {
		friend list;
    private:
		const list<T> *List;
		const node *p;

    public:
		// {{{ construct
		const_iterator() { List = NULL, p = NULL; }
		const_iterator(const list<T> *__List, const node *__p) {
			List = __List;
			p = __p;
		}

		const_iterator(const iterator & other) {
			List = other.List;
			p = other.p;
		}

		const_iterator(const const_iterator & other) {
			List = other.List;
			p = other.p;
		}
		// }}}

		// {{{ ++ and -- 
		// iter++
        const_iterator operator++(int) {
			if (p->right == NULL) throw invalid_iterator();
			const_iterator res = *this;
			p = p->right;
			return res;
		}
        // ++iter
        const_iterator & operator++() {
			if (p->right == NULL) throw invalid_iterator();
			p = p->right;
			return *this;
		}
        // iter--
        const_iterator operator--(int) {
			if (p->left == List->head) throw invalid_iterator();
			const_iterator res = *this;
			p = p->left;
			return res;
		}
        // --iter
        const_iterator & operator--() {
			if (p->left == List->head) throw invalid_iterator();
			p = p->left;
			return *this;
		}
		// }}}

		// {{{ *, ->, == and !=
        T & operator *() const {
			if (p->point == NULL) throw invalid_iterator();
			return *p->point;
		}

		const T * operator ->() const noexcept {
			if (p == NULL) throw invalid_iterator();
			return p->point;
		}

		bool operator == (const iterator &rhs) const {
			return this->p == rhs.p;
		}
		bool operator == (const const_iterator &rhs) const {
			return this->p == rhs.p;
		}
		bool operator != (const iterator &rhs) const {
			return this->p != rhs.p;
		}
		bool operator != (const const_iterator &rhs) const {
			return this->p != rhs.p;
		}
		// }}}
	};
	// }}}

	// {{{ constructor, destructor, and =

    list() {
		head = new node, tail = new node;
		head->right = tail, tail->left = head;
	}

    list(const list &other) {
		head = new node, tail = new node;
		head->right = tail, tail->left = head;
		for (node *p = other.head->right; p != other.tail; p = p->right) {
			node *cur = new node(*p->point);
			insert(tail, cur);
		}
	}

    virtual ~list() {
		for (node *p = head->right, *q; p != tail; p = q) {
			q = p->right;
			delete p;
		}
		delete head;
		delete tail;
	}

    list &operator=(const list &other) {
		if (&other == this) return *this;
		clear();
		head->right = tail, tail->left = head;
		for (node *p = other.head->right; p != other.tail; p = p->right) {
			node *cur = new node(*p->point);
			insert(tail, cur);
		}
		return *this;
	}

	// }}}

	// {{{ front, back, begin and end;

    const T & front() const {
		if (head->right == tail) throw container_is_empty();
		return *head->right->point;
	}
    const T & back() const {
		if (head->right == tail) throw container_is_empty();
		return *tail->left->point;
	}

    iterator begin() {
		iterator res(this, head->right);
		return res;
	}
    const_iterator cbegin() const {
		const_iterator res(this, head->right);
		return res;
	}

    iterator end() {
		iterator res(this, tail);
		return res;
	}
    const_iterator cend() const {
		const_iterator res(this, tail);
		return res;
	}

	// }}}

	// {{{ empty, size and clear

    virtual bool empty() const { return head->right == tail; }
    virtual size_t size() const {
		size_t res = 0;
		for (const_iterator i = cbegin(); i != cend(); ++i) ++res;
		return res;
	}

    virtual void clear() {
		for (node *p = head->right, *q; p != tail; p = q) {
			q = p->right;
			delete p;
		}
		head->right = tail, tail->left = head;
	}

	// }}}

	// {{{ insert and erase

    /**
     * insert value before pos (pos may be the end() iterator)
     * return an iterator pointing to the inserted value
     * throw if the iterator is invalid
     */
    virtual iterator insert(iterator pos, const T &value) {
		if (pos.List != this) throw invalid_iterator();
		node *tmp = new node(value);
		iterator res(this, insert(pos.p, tmp));
		return res;
	}

    /**
     * remove the element at pos (the end() iterator is invalid)
     * returns an iterator pointing to the following element, if pos pointing to the last element, end() will be returned.
     * throw if the container is empty, the iterator is invalid
     */
    virtual iterator erase(iterator pos) {
		if (pos.List != this) throw invalid_iterator();
		if (empty()) throw container_is_empty();
		iterator res(this, erase(pos.p));
		return res;
	}

	// }}}

	// {{{ push and pop

	void push_back(const T &value) { insert(end(), value); }
	void pop_back() {
		if (empty()) throw container_is_empty();
		erase(--end());
	}

	//inserts an element to the beginning.
	void push_front(const T &value) { insert(begin(), value); }

	/**
	 * removes the first element.
	 * throw when the container is empty.
	 */
	void pop_front() {
		if (empty()) throw container_is_empty();
		erase(begin());
	}

	// }}}

	// {{{ sort
	// sort the values in ascending order with operator< of T

	void sort() {
		int len = size(), i = 0;
		T **arr = new T* [len + 1];
		for (iterator it = begin(); it != end(); ++it)
			arr[i++] = new T(*it);
		sjtu::sort<T*> (arr, arr + i, cmp<T*>), i = 0;
		for (iterator it = begin(); it != end(); ++it) *it = *arr[i++];
		for (int i = 0; i < len; ++i) delete arr[i];
		delete [] arr;
	}

	// }}}

	// {{{ merge
	/**
	 * merge two sorted lists into one (both in ascending order)
	 * compare with operator< of T
	 * container other becomes empty after the operation
	 * for equivalent elements in the two lists, the elements from *this shall always precede the elements from other
	 * the order of equivalent elements of *this and other does not change.
	 * no elements are copied or moved
	 */

	void merge(list &other) {
		if (other.empty()) return void();
		node *r = other.head->right, *tmp;
		for (node *l = head->right; l != tail; l = l->right) {
			while (*r->point < *l->point) {
				tmp = r->right, insert(l, r), r = tmp;
				if (r == other.tail) break;
			}
			if (r == other.tail) break;
		}
		while (r != other.tail) tmp = r->right, insert(tail, r), r = tmp;
		other.head->right = other.tail;
		other.tail->left = other.head;
	}
	// }}}

	// {{{ reverse
	/**
	 * reverse the order of the elements
	 * no elements are copied or moved
	 */

	void reverse() {
		for (node *p = head->right, *q; p != tail; p = q) {
			q = p->right;
			p->left->right = p->right;
			p->right->left = p->left;
			p->right = head->right, p->right->left = p;
			p->left = head, p->left->right = p;
		}
	}
	// }}}

	// {{{ unique
	/**
	 * remove all consecutive duplicate elements from the container
	 * only the first element in each group of equal elements is left
	 * use operator== of T to compare the elements.
	 */
	void unique() {
		if (empty()) return void();
		for (node *p = head->right->right, *q; p != tail; p = q) {
			q = p->right;
			if (*p->point == *p->left->point) erase(p);
		}
	}
	// }}}
};

}

#endif //SJTU_LIST_HPP
