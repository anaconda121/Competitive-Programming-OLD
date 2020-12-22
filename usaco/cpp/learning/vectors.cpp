#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    //declaring vector
    vector<int> items; //default
    vector<int> v (5, 50); // {50, 50, 50, 50, 50}

    //adding elements
    items.push_back(100);
    items.push_back(150);
    items.push_back(120);
    items.push_back(110);
    items.push_back(130);
    items.push_back(140);

    //deleting elements
    items.pop_back(); //deletes last element

    cout << items.size() << "\n";
    cout << items[2] << "\n";

    //printing contents of a vector with iterator
    vector<int>::iterator it;
    for (it = items.begin(); it != items.end(); it++) {
        cout << *it << endl;
    }
    cout << "\n";

    //printing elements with auto - for each format
    for (auto element:items) {
        cout << element << endl;
    }
    cout << "\n";

    //sorting vector
    sort(items.begin(), items.end());
    for (auto element:items) {
        cout << element << endl;
    }
    return 0;
}