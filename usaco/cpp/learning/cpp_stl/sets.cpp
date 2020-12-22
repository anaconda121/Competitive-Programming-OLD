#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int main() {
    //set stores number in descending order, so all queries can be done in O(logn)
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

    //upper and lower bound
    //these are more efficent because values are sorted
    //if not able to find, iterator value points to last element in set
    auto it2 = S.lower_bound(-1); //first val that is greater than or equal to -1, in this case -1
    auto it3 = S.upper_bound(-1); //first val that is greater than -1, in this case 1
    if (it2 == S.end()) {
        cout << "lower bound for -1 not present" << endl;
    } else if (it3 == S.end()) {
        cout << "upper bound for -1 not present" << endl;
    } else {
        cout << *it2 << " " << *it3 << endl;
    }

    return 0;
}