#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

#define LARGELENGTH 5

int main (int argc, char* argv[]) {
	if (argc < 2) {
		cout << "Not enough parameters!" << endl;
		return 0;
	}

	ifstream file(argv[1]);
	if (!file) {
		cout << "The file name is invalid." << endl;
		return 0;
	}

	int wordCount = 0;

	string line;
	while (getline(file, line)) {
		stringstream str(line);
		string word;
		while (getline(str, word, ' ')) {
			if (word.size() > LARGELENGTH) {
				wordCount++;
				cout << word << ",";
			}
		}
	}

	cout << "\nThere were " << wordCount << " word(s) with length"
	     << " greater than " << LARGELENGTH << "." << endl;
}
