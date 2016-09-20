#include <iostream>
using namespace std;

int main () {
    string thing = "apple,pear,peach,thing";
    int comma = thing.find_first_of(',');

    while (comma != -1) {
        string word = thing.substr(0, comma);
        cout << word << endl;
        thing = thing.substr(comma+1);
        comma = thing.find_first_of(',');
    }

    cout << thing << endl;
}
