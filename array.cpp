#include <iostream>
using namespace std;

int iterate (int size, int arr []) {
    int max = arr[0];
    for (int i = 0; i < size; i++) {
        if (arr[i] > max) max = arr[i];
    }
    return max;
}

int main () {
    int arr [] = {1,2,3,1,4,5,3,2,0};
    cout << "Max: " << iterate(9, arr) << endl;
}
