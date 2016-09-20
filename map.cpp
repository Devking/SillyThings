#include <iostream>
#include <map>
using namespace std;

int main () {
    map<string, int> count;

    string thing = "word";

    count.insert(pair<string,int>(thing, 10));

    auto itr = count.find(thing);
    if (itr != count.end()) {
        cout << itr->first << " " << itr->second << endl;
    }
}
