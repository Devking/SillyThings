#include <iostream>
using namespace std;

void recursiveBin (int a) {
	if (a < 1) return;
	recursiveBin(a/2);
	cout << a%2;
}

void iterativeBin (int a) {
	string b = "";
	while (a > 0) {
		b = b + (a%2 ? '1' : '0');
		a /= 2;
	}
	cout << b << endl;
}

int main () {
	int a = 5;
	a >>= 1;
	cout << a << endl;

	int b = 0x11;
	cout << b << endl;
	recursiveBin(b);
	cout << endl;
	iterativeBin(b);
}
