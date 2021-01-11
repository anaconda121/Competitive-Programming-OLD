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

int closest_num(vector<int> &a, int query) {
    int l = 0;
    int r = a.size()-1;
    while (l < r) {
        int mid = (l + r) / 2;
        if (a[mid] > query) {
            r = mid;
        } else if (a[mid] <= query) {
            l = mid;
        } else if (a[mid] == query) {
            return a[mid];
        }
    }
    return a[l];
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

    vector<int> v;
    v.push_back(3);
    v.push_back(5);
    v.push_back(7);
    v.push_back(9);
    v.push_back(16);
    cout << closest_num(v, 14) << endl;
    return 0;
}