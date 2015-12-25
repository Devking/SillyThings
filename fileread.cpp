#include <iostream>
#include <set>
#include <fstream>
using namespace std;

void loadCollection(set<string>& collection) {
	ifstream coll ("coll.txt");
	if (!coll) {
		cout << "The collection file does not exist. Making empty collection file now.\n" << endl;
		ofstream o ("coll.txt");
	} else {
		cout << "The collection file has been successfully loaded.\n" << endl;
		string gamma;
		while (getline(coll, gamma, ',')) {
			if (gamma != "\n") collection.insert(gamma);
		}
	}
}

// Saves back the entire string, instead of adding just the newest additions
void saveCollection(const set<string>& collection) {
	ofstream coll ("coll.txt");
	for (set<string>::const_iterator itr = collection.begin(); itr != collection.end(); itr++)
		coll << *itr << ",";
	cout << "\nCollection has been saved!" << endl;
}

void addString(set<string>& collection) {
	string str;
	cout << "\nWhat string would you like to add?\n> ";
	cin >> str;

	if (collection.find(str) != collection.end()) {
		cout << "\nThat string is already in the collection." << endl;
	} else {
		collection.insert(str);
		cout << "\n'" << str << "' has been added to the repository." << endl;
	}
}

void printString(const set<string>& collection) {
	cout << "\nCurrent Collection:" << endl;
	for (set<string>::const_iterator itr = collection.begin(); itr != collection.end(); itr++)
		cout << *itr << " ";
	cout << endl;
}

void findString(const set<string>& collection) {
	string str;
	cout << "\nWhat string would you like to find?\n> ";
	cin >> str;

	if (collection.find(str) != collection.end()) {
		cout << "\nYes, '" << str << "' is in the collection.\n";
	} else {
		cout << "\nNo, '" << str << "' is not in the collection.\n";
	}
}

void menu (set<string>& collection) {
	bool running = true;
	while (running) {
		string option;
		cout << "Select an option: " << endl;
		cout << "1: Add String" << endl;
		cout << "2: Print String" << endl;
		cout << "3: Find String" << endl;
		cout << "4: Save Collection" << endl;
		cout << "5: Quit" << endl;
		cout << "> ";
		cin >> option;
		switch (option[0]) {
			case '1': addString(collection); break;
			case '2': printString(collection); break;
			case '3': findString(collection); break;
			case '4': saveCollection(collection); break;
			case '5': running = false; break;
			default: cout << "\nNot a valid input. Try again."; break;
		}
		cout << endl;
	}
}

int main () {
	cout << "\nWelcome to this program." << endl << endl;
	set<string> collection;
	loadCollection(collection);
	menu(collection);
	cout << "Thank you for using this program." << endl;
}
