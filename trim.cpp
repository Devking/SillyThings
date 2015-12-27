#include <iostream>
using namespace std;

string trimSpaces (const string& str) {
	if (str.empty()) return str;
	int start = str.find_first_not_of(' ');
	int end = str.find_last_not_of(' ');
	return str.substr(start, (end-start+1));
}

int main () {
	string test = "abc";
	string test2 = "";
	string test3 = " a b c";
	string test4 = "a b c ";
	string test5 = " a ";

	cout << trimSpaces(test) << endl;
	cout << trimSpaces(test2) << endl;
	cout << trimSpaces(test3) << endl;
	cout << trimSpaces(test4) << endl;
	cout << trimSpaces(test5) << endl;
}
