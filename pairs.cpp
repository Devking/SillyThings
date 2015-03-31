#include <iostream>
#include <vector>
using namespace std;

struct Set {
	Set (int mi, int ma, int i, int j) 
	: min(mi), max(ma), xi(i), xj(j) {}
	int min;
	int max;
	int xi;
	int xj;
};

int minFind(vector<int>::iterator begin, vector<int>::iterator end) {
	if (begin == end) return -1;
	if (begin+1 == end) return *begin;
	int min = *begin;
	while (begin != end) {
		if (*begin < min) min = *begin;
		begin++;
	}
	return min;
}

int maxFind(vector<int>::iterator begin, vector<int>::iterator end) {
	if (begin == end) return -1;
	if (begin+1 == end) return *begin;
	int max = *begin;
	while (begin != end) {
		if (*begin > max) max = *begin;
		begin++;
	}
	return max;
}

// [min, max, xi, xj]

Set recursed (vector<int>::iterator begin, vector<int>::iterator end) {
	// if only one element
	if (begin+1 == end) return Set(*begin, *begin, *begin, *begin);

	// get min and max of entire collection
	int min = minFind(begin, end);
	int max = maxFind(begin, end);

	// if only two elements
	if (begin+2 == end) return Set(min, max, *begin, *(begin+1));

	// otherwise, we will divide!
	vector<int>::iterator mid = begin + (end-begin)/2;
	Set left = recursed(begin, mid);
	Set right = recursed(mid, end);

	// check left range, right range, total range
	int leftrange = left.xj - left.xi;
	int rightrange = right.xj - right.xi;
	int bestrange = right.max - left.min;

	// return the greatest of the three
	if (leftrange > rightrange && leftrange > bestrange) {
		return Set(min, max, left.xi, left.xj);
	} else if (rightrange > leftrange && rightrange > bestrange) {
		return Set(min,max, right.xi, right.xj);
	}
	return Set(left.min, right.max, left.min, right.max);
}

void recurse (vector<int>& a) {
	if (a.size() == 0) return;
	Set thing = recursed(a.begin(), a.end());
	cout << thing.xi << " " << thing.xj << endl;
}

int main() {
	vector<int> a {1,2,3,4,5};
	recurse(a);
}