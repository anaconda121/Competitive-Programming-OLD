#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

//A multiset is a sorted set that allows multiple copies of the same element.
//In addition to all of the regular set operations,
//the count() method returns the number of times an element is present in the multiset. 
//However, this method takes time linear in the number of matches so you shouldn't use it in a contest.
//If you want to remove a value once, make sure to use multiset.erase(multiset.find(val)) rather than multiset.erase(val). The latter will remove all instances of val.

int main(){
    multiset<int> ms;
    ms.insert(1); // [1]
    ms.insert(14); // [1, 14]
    ms.insert(9); // [1, 9, 14]
    ms.insert(2); // [1, 2, 9, 14]
    ms.insert(9); // [1, 2, 9, 9, 14]
    ms.insert(9); // [1, 2, 9, 9, 9, 14]
    cout << ms.count(4) << '\n'; // 0
    cout << ms.count(9) << '\n'; // 3
    cout << ms.count(14) << '\n'; // 1
    ms.erase(ms.find(9));
    cout << ms.count(9) << '\n'; // 2
    ms.erase(9);
    cout << ms.count(9) << '\n'; // 0
}