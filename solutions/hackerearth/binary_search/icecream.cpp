#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void findSum(vector<int> a, vector<int> b, int sum) {
    int l = 0;
    int r = a.size() - 1;
    while (l < r) {
        if (a[l] + a[r] == sum) {
            vector<int>::iterator it;
            it = find(begin(b), end(b),a[l]);
            vector<int>::iterator it2;
            it2 = find(begin(b), end(b),a[r]);
            if (it - begin(b) == it2 - begin(b)) {
                cout << l+1 << " " << r+1 << endl; 
            } else {
                cout << it - begin(b)+1 << " " << it2 - begin(b)+1 << endl; 
            }
            break;
        } else if (a[l] + a[r] < sum) {
            l++; 
        } else {
            r--;
        }
    }
}

void setIO(string name = "") { // name is nonempty for USACO file I/O
    ios_base::sync_with_stdio(0); cin.tie(0); // see Fast Input & Output
    // alternatively, cin.tie(0)->sync_with_stdio(0);
    freopen((name+".in").c_str(), "r", stdin); // see Input & Output
    freopen((name+".out").c_str(), "w", stdout);
}


int main() {
    setIO("icecream");
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int m;
        cin >> m;
        int n;
        cin >> n;
        vector<int> flavors (n);
        vector<int> clone (n);
        for (int j = 0; j < n; j++) {
            cin >> flavors[j];
            clone[j] = flavors[j];
        }
        sort(begin(flavors), end(flavors));
        findSum(flavors, clone, m);
    }
    return 0;
}