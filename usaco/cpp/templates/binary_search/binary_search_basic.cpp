#include <iostream>
#include <algorithm>
#include <vector>
#include <stdlib.h>

using namespace std;

int binary_search(vector<int> &a, int query) {
    int left = 0, right = a.size() - 1; 
    while (left < right) {
        int middle = (left + right) / 2; //getting middle value of available vals
        if (a[middle] < query) {
            left = middle + 1; //vals from a[left] - a[middle] are all less than query b/c a is sorted
        } else {
            right = middle; //vals from a[middle] - a[right] are all greater than query 
        }
    }
    if (a[left] == query) {
        return left;
    }
    return -1;
}

int main() {
    vector<int> a;
    int idx[20];
    for (int i = 0; i < 20; i++) {
        a.push_back(i);
    }
    sort(a.begin(), a.end()); //sorting array to prepare it for binary search
    for (int i = 0; i < 20; i++) {
        idx[i] = binary_search(a, rand() % 20);
        cout << idx[i] << " -- " << a[idx[i]] << endl;
    }
    return 0;
}