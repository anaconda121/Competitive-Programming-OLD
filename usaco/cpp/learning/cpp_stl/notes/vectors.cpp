#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool ascending(int x, int y) {
    return x > y;
}

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
    items.push_back(140);
    items.push_back(140);
    items.push_back(140);
    items.push_back(140);
    items.push_back(140);

    //deleting elements
    items.pop_back(); //deletes last element
    v.erase(v.begin() + 1); //deleting element at index 1
    v.erase(v.begin(), v.begin()+3); //erases first 3 elements

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

    //sorting vector in descending order
    sort(items.begin(), items.end(), ascending);
    for (auto element:items) {
        cout << "ascending order : " << element << endl;
    }

    //finding if an element is present in a vector
    //present gives index number if element is present, otherwise it returns 0
    bool present = binary_search(items.begin(), items.end(), 150);
    cout << "\n" << present << endl;

    //lowerbound - gives value of first element that is greater than or equal to 3rd parameter
    //upperbound - gives value of first element that is greater than 3rd parameter
    it = lower_bound(items.begin(), items.end(), 140);
    vector<int>::iterator it2 = upper_bound(items.begin(), items.end(), 140);
    cout << "\n" << *it << " " << *it2 << endl;
    cout << it2 - it << endl; //gets # of times number in lower bound occurs

    return 0;
}