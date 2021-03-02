#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

/*void setIO(string name = "") { // name is nonempty for USACO file I/O
    ios_base::sync_with_stdio(0); cin.tie(0); // see Fast Input & Output
    // alternatively, cin.tie(0)->sync_with_stdio(0);
    freopen((name+".in").c_str(), "r", stdin); // see Input & Output
    freopen((name+".out").c_str(), "w", stdout);
}*/

int minCost(vector<int> a) {
    sort(begin(a), end(a));
    int mid = a.size() / 2; //mid index, idx of number that we want to change every other number to
}

int main() {
    //setIO("stick");
    int n;
    cin >> n;
    vector<int> x;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        x.push_back(a);
    }
    int cost = minCost(x);
    cout << cost << endl;
    return 0;
}