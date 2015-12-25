#include <iostream>
using namespace std;

int doub (int val) {
	return val*2;
}

int nega (int val) {
	return val*-1;
}

int squa (int val) {
	return val*val;
}

int operation (int val, int (*callback)(int)) {
	return callback(val);
}

int main () {
	int num;
	cout << "Enter a number:\n> ";
	cin >> num;

	string val;
	cout << "Pick an operation:" << endl;
	cout << "1: Double" << endl;
	cout << "2: Negate" << endl;
	cout << "3: Square" << endl;
	cout << "> ";
	cin >> val;

	switch (val[0]) {
		case '1': cout << "The double is: " << operation(num, doub) << endl; break;
		case '2': cout << "The negation is: " << operation(num, nega) << endl; break;
		case '3': cout << "The square is: " << operation(num, squa) << endl; break;
		default: break;
	}
}
