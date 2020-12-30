#include <iostream>
#include <set>

using namespace std;

void print_set(set<int>s2) {
    set<int, greater<int> >::iterator itr; //prints set from least to greatest

    for (itr = s2.begin(); itr != s2.end(); ++itr) {
        cout << *itr << ",";
    }
    cout << endl;
}
