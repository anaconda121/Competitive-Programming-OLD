#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int binary_search(vector<int> &a, int query) {
    vector<int>::iterator it;
    it = lower_bound(a.begin(), a.end(), query);
    if (*it == query) {
        return it - a.begin();
    }
    return -1;
}


int main() {
    vector<int> a;
    int idx[20];
    for (int i = 0; i < 20; i++) {
        a.push_back(i);
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < 20; i++) {
        idx[i] = binary_search(a, rand() % 20);
        cout << idx[i] << " -- " << a[idx[i]] << endl;
    }
    
    return 0;
}