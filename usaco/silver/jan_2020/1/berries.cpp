#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long;

void setIO(string name = "") { // name is nonempty for USACO file I/O
    ios_base::sync_with_stdio(0); cin.tie(0); // see Fast Input & Output
    // alternatively, cin.tie(0)->sync_with_stdio(0);
    freopen((name+".in").c_str(), "r", stdin); // see Input & Output
    freopen((name+".out").c_str(), "w", stdout);
}

int main() {
    setIO("berries");
    int n,k;
    cin >> n >> k;
    vector<int> b (n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    sort(begin(b),end(b));
    vector<int> buckets;
    buckets.push_back(b[n-1]/2);
    //cout << b[n-1]/2 << endl;
    buckets.push_back(b[n-1] - b[n-1]/2);
    //cout << b[n-1] - b[n-1]/2 << "\n" << endl;
    for (int i = 2; i < k; i++) {
        buckets.push_back(b[n-i]);
    }
    sort(begin(buckets),end(buckets));
    int sum = 0;
    for (int i = 0; i < k/2; i++) {
        sum += buckets[i];
    }
    cout << sum << endl;
}