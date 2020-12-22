#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int main() {
    //set stores number in ascending order, so all queries can be done in O(logn)
    //declaring a set
    set<int> S;
    S.insert(1);
    S.insert(2);
    S.insert(-10);
    S.insert(-1);

    //printing elements of a set 
    for (auto element : S) {
        cout << element << " ";
    }
    cout << endl;

    //querying for values in set
    auto it = S.find(-1);
    if (it == S.end()) {
        cout << "not present" << endl;;
    } else {
        cout << *it << endl;
    }

    return 0;
}