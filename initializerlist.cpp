#include <iostream>
#include <vector>
#include <initializer_list>
using namespace std;

const int DEFAULT_CAP = 16;

template <class Object>
class Vector {
public:

	Vector () : len(0), capacity(DEFAULT_CAP) {
		arr = new Object[capacity];
	}

	Vector (initializer_list<Object> lis) {
		len = lis.size();
		capacity = len * 2 + 1;
		arr = new Object[capacity];
		int index = 0;
		for (auto itr = lis.begin(); itr != lis.end(); itr++) {
			arr[index] = *itr;
			index++;
		}
	}

	void printVec () const {
		for (int i = 0; i < len; i++) cout << arr[i] << " ";
		cout << endl;
	}

	void resize () {
		capacity *= 2;
		Object* arr2 = new Object[capacity];
		for (int i = 0; i < len; i++) {
			arr2[i] = arr[i];
		}
		delete [] arr;
		arr = arr2;
	}

	void push_back (const Object& obj) {
		if (len + 1 >= capacity) resize();
		arr[len] = obj;
		len++;
	}

	void pop_back () { len ? len-- : 0; }

	int size() const { return len; }
	bool empty() const { return len == 0; }

private:
	Object* arr;
	int len;
	int capacity;
};

int main () {
	Vector<int> a {1,2,3};
	a.printVec();

	for (int i = 0; i < 100; i++) {
		a.push_back(i);
	}
	a.printVec();

	while (!a.empty()) {
		a.pop_back();
	}
	a.printVec();

}
