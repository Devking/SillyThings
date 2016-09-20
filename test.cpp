#include <iostream>
#include <map>
using namespace std;

int linearSum (int* thing, int size) {
	int total = 0;
	for (int i = 0; i < size; i++) {
		total += thing[i];
	}
	return total;
}

int divConSum (int* thing, int left, int right) {
	if (left == right) return 0;
	if (left == right - 1) return thing[left];
	int mid = (left + right) / 2;
	return divConSum(thing, left, mid) + divConSum(thing, mid,right);
}

int dirChange (int* thing, int size) {
	int changes = 0;
	if (size < 3) return 0;
	char dir = 'p';
	if (thing[1] < thing[0]) dir = 'n';
	for (int i = 2; i < size; i++) {
		if (thing[i] > thing[i-1] && dir == 'n') {
			dir = 'p';
			changes++;
		} else if (thing[i] < thing[i-1] && dir == 'p') {
			dir = 'n';
			changes++;
		}
	}
	return changes;
}

char commonChar (const string& elem) {
	map<char, int> track;

	char common;
	int count = 0;

	for (char a : elem) {
		if (track.find(a) != track.end()) {
			track[a]++;
			if (track[a] > count) {
				common = a;
				count = track[a];
			}
		} else {
			track[a] = 1;
			if (track[a] > count) {
				common = a;
				count = track[a];
			}
		}
	}

	return common;
}

int greatestGain (int* arr, int size) {
	if (size < 2) return 0;
	int min = arr[0];
	int diff = arr[1] - arr[0];
	for (int i = 1; i < size; i++) {
		if (arr[i] < min) {
			min = arr[i];
		} else {
			int newdiff = arr[i] - min;
			if (newdiff > diff) diff = newdiff;
		}
	}
	return diff;
}

int main () {
  int thing [] = {1,2,-5, 10, 12, 11, -11};

  cout << "Sum using linear algo: " << linearSum(thing, 7) << endl;
  cout << "Sum using div/conquer: " << divConSum(thing, 0, 7) << endl;
  cout << "Direction changes    : " << dirChange(thing, 7) << endl;

  cout << endl;

  string elem = "aabbccddefgbachffffaaa";
  cout << "Most common char     : " << commonChar(elem) << endl;

  int prices [] = {1,-1,0};
  cout << endl;
  cout << "Largest difference   : " << greatestGain(prices, 3) << endl;
}
