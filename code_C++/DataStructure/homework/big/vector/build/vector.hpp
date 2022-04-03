#ifndef SJTU_VECTOR_HPP
#define SJTU_VECTOR_HPP

#include "exceptions.hpp"

#include <climits>
#include <cstddef>

namespace sjtu {

/**
 * a data container like std::vector
 * store data in a successive memory and support random access.
 */

template<typename T>
class vector {
private:
	size_t Size;
	size_t maxSize;
	T **a;

	void expand() {
		maxSize = (maxSize + 1) * 3 / 2;
		T **tmp = new T* [maxSize + 1];
		for (int i = 0; i < Size; ++i) tmp[i] = a[i];
		delete [] a;
		a = tmp;
	}

public:
    class const_iterator;
	// {{{ iterator
    class iterator {
    private:
		vector<T> * __TheVector;
		size_t p;

	public:
		//construct
		iterator(vector<T> * _TheVector = NULL, size_t _p = 0) { 
			__TheVector = _TheVector;
			p = _p;
		}

		size_t point() { return p; }

		/**
		 * return a new iterator which pointer n-next elements
		 * as well as operator-
		 */
		iterator operator + (const int &n) const {
			iterator res;
			res.__TheVector = __TheVector;
			res.p = p + n;
			return res;
		}
		iterator operator - (const int &n) const {
			iterator res;
			res.__TheVector = __TheVector;
			res.p = p - n;
			return res;
		}

		// return the distance between two iterators,
		// if these two iterators point to different vectors, throw invalid_iterator.
		int operator - (const iterator &rhs) const {
			if (__TheVector != rhs.__TheVector)
				throw invalid_iterator();
			else return p - rhs.p;
		}

		iterator& operator += (const int &n) { p += n; return *this; }
		iterator& operator -= (const int &n) { p -= n; return *this; }

		//iter++
		iterator operator ++ (int) {
			iterator res = *this;
			*this += 1;
			return res;
		}
		//++iter
		iterator& operator ++ () { *this += 1; return *this; }

		//iter--
		iterator operator -- (int) {
			iterator res = *this;
			*this -= 1;
			return res;
		}
		// --iter
		iterator& operator -- () { *this -= 1; return *this; }

		T& operator*() const { return __TheVector->at(p); }
		bool operator == (const iterator &rhs) const
		{ return __TheVector == rhs.__TheVector and p == rhs.p; }
		bool operator == (const const_iterator &rhs) const
		{ return __TheVector == rhs.__TheVector and p == rhs.p; }

		bool operator != (const iterator &rhs) const
		{ return __TheVector != rhs.__TheVector or p != rhs.p; }
		bool operator != (const const_iterator &rhs) const
		{ return __TheVector != rhs.__TheVector or p != rhs.p; }
	};
	// }}}

	// {{{ const_iterator
	// has same function as iterator, just for a const object.
	class const_iterator {
	private:
		const vector<T> * __TheVector;
		size_t p;

	public:
		// construct
		const_iterator(const vector<T> *_Vector = NULL, size_t _p = 0) { 
			__TheVector = _Vector;
			p = _p;
		}

		/*
		 * return a new const_iterator which pointer n-next elements
		 * as well as operator-
		 */
		const_iterator operator + (const int &n) const {
			const_iterator res;
			res.__TheVector = __TheVector;
			res.p = p + n;
			return res;
		}
		const_iterator operator - (const int &n) const {
			const_iterator res;
			res.__TheVector = __TheVector;
			res.p = p - n;
			return res;
		}

        // return the distance between two const_iterators,
        // if these two const_iterators point to different vectors, throw invalid_const_iterator.
        int operator - (const const_iterator &rhs) const {
			if (__TheVector != rhs.__TheVector)
				throw invalid_iterator();
			else return p - rhs.p;
        }

        const_iterator& operator += (const int &n) { p += n;return *this; }
        const_iterator& operator -= (const int &n) { p -= n;return *this; }

		//iter++
        const_iterator operator ++ (int) {
			const_iterator res = *this;
			*this += 1;
			return res;
		}
		//++iter
        const_iterator& operator ++ () { *this += 1; return *this; }

		//iter--
        const_iterator operator -- (int) {
			const_iterator res = *this;
			*this -= 1;
			return res;
		}
		// --iter
        const_iterator& operator -- () { *this -= 1; return *this; }

		const T& operator*() const { return __TheVector->at(p); }
		bool operator == (const iterator &rhs) const
		{ return __TheVector == rhs.__TheVector and p == rhs.p; }
		bool operator == (const const_iterator &rhs) const
		{ return __TheVector == rhs.__TheVector and p == rhs.p; }

		bool operator != (const iterator &rhs) const
		{ return __TheVector != rhs.__TheVector or p != rhs.p; }
		bool operator != (const const_iterator &rhs) const
		{ return __TheVector != rhs.__TheVector or p != rhs.p; }
    };
	//}}}

	// {{{ construct destruct and =
    vector() { Size = maxSize = 0, a = NULL; }
    vector(const vector &other) {
		Size = other.size();
		maxSize = other.maxSize;
		a = new T * [maxSize + 1];
		for (int i = 0; i < Size; ++i)
			a[i] = new T(*other.a[i]);
	}
    ~vector() {
		for (int i = 0; i < Size; ++i) delete a[i];
		delete [] a;
	}

    vector & operator = (const vector &other) {
		if (&other == this) return *this;
		for (int i = 0; i < Size; ++i) delete a[i];
		delete [] a;
		Size = other.size();
		maxSize = other.maxSize;
		a = new T * [maxSize + 1];
		for (int i = 0; i < Size; ++i)
			a[i] = new T(*other.a[i]);
		return *this;
	}
	//}}}

    /** {{{ at and []
     * assigns specified element with bounds checking
     * throw index_out_of_bound if pos is not in [0, size)
     */
    T & at(const size_t &pos) {
		if (pos < 0 or pos >= Size)
			throw index_out_of_bound();
		else return *a[pos];
	}
    const T & at(const size_t &pos) const {
		if (pos < 0 or pos >= Size)
			throw index_out_of_bound();
		else return *a[pos];
	}

    /**
     * assigns specified element with bounds checking
     * throw index_out_of_bound if pos is not in [0, size)
     */
    T & operator [] (const size_t &pos) {
		if (pos < 0 or pos >= Size)
			throw index_out_of_bound();
		else return *a[pos];
	}
    const T & operator [] (const size_t &pos) const {
		if (pos < 0 or pos >= Size)
			throw index_out_of_bound();
		else return *a[pos];
	}
	// }}}

	/** {{{ front, back, begin and end
	 * access the first element.
	 * throw container_is_empty if size == 0
	 */
	const T & front() const {
		if (!Size) throw container_is_empty();
		else return **a;
	}
	/**
	 * access the last element.
	 * throw container_is_empty if Size == 0
	 */
	const T & back() const {
		if (!Size) throw container_is_empty();
		else return *(a[Size - 1]);
	}

	/**
	 * returns an iterator to the beginning.
	 */
	iterator begin() {
		iterator res(this, 0);
		return res;
	}
	const_iterator cbegin() const {
		const_iterator res(this, 0);
		return res;
	}

	/**
	 * returns an iterator to the end.
	 */
	iterator end() {
		iterator res(this, Size);
		return res;
	}
	const_iterator cend() const {
		const_iterator res(this, Size);
		return res;
	}
	//}}}

	// {{{ empty, size and clear

	// checks whether the container is empty
	bool empty() const { return !Size; }

	// returns the number of elements
	size_t size() const { return Size; }

	// clears the contents
	void clear() {
		for (int i = 0; i < Size; ++i) delete a[i];
		delete [] a;
		Size = maxSize = 0;
	}
	// }}}

	// {{{ insert and erase
	/**
	 * inserts value before pos
	 * returns an iterator pointing to the inserted value.
	 */
	iterator insert(iterator pos, const T &value) {
		if (Size == maxSize) expand();
		++Size;
		for (size_t i = Size - 1; i > pos.point(); --i) a[i] = a[i - 1];
		a[pos.point()] = new T(value);
		return pos;
	}

	/**
	 * inserts value at index ind.
	 * after inserting, this->at(ind) == value
	 * returns an iterator pointing to the inserted value.
	 * throw index_out_of_bound if ind > size (in this situation ind can be size because after inserting the size will increase 1.)
	 */
	iterator insert(const size_t &ind, const T &value) {
		if (ind > Size) throw index_out_of_bound();
		if (Size == maxSize) expand();
		++Size;
		for (int i = Size - 1; i > ind; --i) a[i] = a[i - 1];
		a[ind] = new T(value);
		return begin() + ind;
	}

	/**
	 * removes the element at pos.
	 * return an iterator pointing to the following element.
	 * If the iterator pos refers the last element, the end() iterator is returned.
	 */
	iterator erase(iterator pos) {
		--Size;
		delete a[pos.point()];
		for (iterator i = pos; i != end(); ++i)
			a[i.point()] = a[(i + 1).point()];
		return pos;
	}

	/**
	 * removes the element with index ind.
	 * return an iterator pointing to the following element.
	 * throw index_out_of_bound if ind >= size
	 */
	iterator erase(const size_t &ind) {
		if (ind >= size) throw index_out_of_bound();
		--Size;
		delete a[ind];
		for (int i = ind; i < Size; ++i)
			a[i] = a[i + 1];
		return begin() + ind;
	}
	// }}}

	// {{{ push_back and pop_back
	// adds an element to the end.
	void push_back(const T &value) {
		if (Size == maxSize) expand();
		++Size;
		a[Size - 1] = new T(value);
	}
	/**
	 * remove the last element from the end.
	 * throw container_is_empty if size() == 0
	 */
	void pop_back() {
		if (Size == 0) throw container_is_empty();
		delete a[--Size];
	}
	// }}}
};


}

#endif
