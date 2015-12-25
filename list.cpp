#include <iostream>
using namespace std;

template <class Object>
class List {
public:
	List () : head(nullptr) {}
	List (const List& rhs) : head(nullptr) {
		Node* rHead = rhs.head;

		if (rHead) {
			head = new Node (rHead->value);
			rHead = rHead->next;
		}

		Node* trailer = head;

		while (rHead) {
			Node* nNode = new Node (rHead->value);
			trailer->next = nNode;
			trailer = trailer->next;
			rHead = rHead->next;
		}
	}
	void push_front (const Object& val) {
		head = new Node(val, head);
	}
	void pop_front () {
		if (head) {
			Node* next = head->next;
			delete head;
			head = next;
		}
	}
	Object& front () const {
		return head->value;
	}
	void printList () const {
		Node* temp = head;
		while (temp) {
			cout << temp->value << " ";
			temp = temp->next;
		}
		cout << endl;
	}
	bool empty () const {
		return !head;
	}
private:
	struct Node {
		Node (const Object& val, Node* ne = nullptr) : value(val), next(ne) {}
		Object value;
		Node* next;
	};
	Node* head;
};

int main () {
	List<int> a;
	a.push_front(5);
	cout << a.front() << endl;
	a.push_front(3);
	a.push_front(1);
	a.printList();
	a.pop_front();
	a.printList();
	a.push_front(7);
	a.push_front(10);
	a.push_front(11);
	a.printList();
	while (!a.empty()) {
		a.pop_front();
		a.printList();
	}

	a.push_front(13);
	a.push_front(15);
	a.push_front(16);
	a.printList();
	List<int> b = a;

	a.printList();
	b.printList();
	a.pop_front();
	a.printList();
	b.printList();
}
