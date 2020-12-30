#include <iostream>
#include <set>

using namespace std;

void print_set(set<int>s2) {
    for (auto itr = s2.begin(); itr != s2.end(); ++itr) {
        cout << *itr << ",";
    }
    cout << endl;
}
