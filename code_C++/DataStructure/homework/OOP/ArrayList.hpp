/***********************************************************
  > File Name: 1469.cpp
  > Author: TALBW
  > Created Time: Tue 22 Feb 2022 03:52:39 PM CST
 *******************************************************/

#ifndef ArrayList_hpp
#define ArrayList_hpp
#define USE_OS

#include <bits/stdc++.h>

using namespace std;

class error : public std::exception {
private:
    std::string msg;

public:
    explicit error(const char *_msg_) : msg(_msg_) {}

    const char *toString() {
        return msg.c_str();
    }
};

template <class T>
class ArrayList {
private:
	int len;
	T *a;

public:
	~ArrayList() { delete [] a; }
	ArrayList() { len = 0; a = NULL; }

	ArrayList(int n) {
		if (n < 0) throw error("invalid length");
		len = n, a = new T [n];
	}
	ArrayList(T *arr, int n) {
		if (n < 0) throw error("invalid length");
		len = n;
		a = new T [n];
		for (int i = 0; i < n; ++i)
			a[i] = arr[i];
	}

	ArrayList(const ArrayList &b) {
		len = b.len;
		a = new T [len];
		for (int i = 0; i < len; ++i)
			a[i] = b[i];
	}

	int size() { return len; }
	T & operator [] (int p) {
		if (p >= len or p < 0) throw error("index out of bound");
		return a[p];
	}
	T & operator [] (int p) const {
		if (p >= len or p < 0) throw error("index out of bound");
		return a[p];
	}

	template <class Tp>
	friend ArrayList<Tp> operator + (ArrayList<Tp> a, ArrayList<Tp> b);

	ArrayList<T> operator = (ArrayList<T> b) {
		if (len < b.len) {
			delete [] a;
			a = new T [b.len];
		}
		len = b.len;
		for (int i = 0; i < len; ++i) a[i] = b[i];
		return *this;
	}

	template <class Tp>
	friend bool operator == (ArrayList<Tp> a, ArrayList<Tp> b);
	template <class Tp>
	friend ostream & operator << (ostream &, ArrayList<Tp>);
};

template <class T>
ostream & operator << (ostream & out, ArrayList<T> a) {
	for (int i = 0; i < a.len - 1; ++i)
		out << a[i] << ' ';
	out << a[a.len - 1];
	return out;
}

template <class T>
ArrayList<T> operator + (ArrayList<T> a, ArrayList<T> b) {
	ArrayList<T> res;
	res.len = a.len + b.len;
	res.a = new T [res.len];
	for (int i = 0; i < a.len; ++i)
		res[i] = a[i];
	for (int i = 0; i < b.len; ++i)
		res[a.len + i] = b[i];
	return res;
}

template <class T>
bool operator == (ArrayList<T> a, ArrayList<T> b) {
	if (a.len != b.len) return false;
	for (int i = 0; i < a.len; ++i)
		if (!(a[i] == b[i])) return false;
	return true;
}

template <class T>
bool operator != (ArrayList<T> a, ArrayList<T> b) { return !(a == b); }


#endif

/*
template <class T>
void printList(ArrayList<T> list) {
    std::cout << list << "\n";
}
int main() {
	try {
		ArrayList<char> list_err(-1);
	} catch (error &e) {
		std::cout << e.toString() << std::endl;
	}

	ArrayList<int> list(5);

	try {
		list[-1];
	} catch (error &e) {
		std::cout << e.toString() << std::endl;
	}
	try {
		list[2000];
	} catch (error &e) {
		std::cout << e.toString() << std::endl;
	}

	for (int i = 0; i < list.size(); i++) list[i] = i;
	printList(list);
	ArrayList<int> temp = list;
	printList(temp);
	temp = list;
	printList(temp);
	if (temp == list) std::cout << "true" << std::endl;

	int arr[5] = {4, 215, 12, 84, 76};
	const ArrayList<int> list_const(arr, 5);
	std::cout << list_const[3] << std::endl;
	printList(list_const);

	printList(list_const + list);

	return 0;
}
*/
