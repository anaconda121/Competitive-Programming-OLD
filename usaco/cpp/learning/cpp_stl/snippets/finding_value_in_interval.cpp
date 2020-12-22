#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <limits>

using namespace std;

/* problem statement: given a number, find the interval in the set<pair<int,int>> that the number falls in */

set<pair<int,int>> S;

void findInterval(int point, set<pair<int,int>> S) {
    auto it = S.upper_bound({point, 10000}); //10000 is max value for this problem
    if (it == S.begin()) {
        //this means value is smaller than all values in set
        cout << "-1" << endl;
        return;
    }
    it--;
    pair<int,int> current = *it;
    if (current.first <= point && point <= current.second) {
        cout << "starting value in interval " << current.first << " , " << "ending value in interval " << current.second << endl;
    } else {
        cout << "-1" << endl;
    }
}

int main() {
    //inserting pairs into set
    S.insert({10,20});
    S.insert({30,400});
    S.insert({401,450});
    S.insert({2,3});

    //calling function
    findInterval(10,S);
    return 0;
}