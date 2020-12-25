#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int sum(vector<int>&a, int idx) {
    int sum = 0;
    for (int i = 0; i < idx; i++) {
        sum += a[i];
    }
    return sum;
}

void setIO(string name = "") { // name is nonempty for USACO file I/O
    ios_base::sync_with_stdio(0); cin.tie(0); // see Fast Input & Output
    // alternatively, cin.tie(0)->sync_with_stdio(0);
    freopen((name+".in").c_str(), "r", stdin); // see Input & Output
    freopen((name+".out").c_str(), "w", stdout);
}

int main() {
    setIO("bishu");
    int n;
    cin >> n;
    vector<int> soldiers (n);
    for (int i = 0; i < n; i++) {
        cin >> soldiers[i];
    }
    int q;
    cin >> q;
    vector<int> power (q);
    sort(begin(soldiers), end(soldiers));
    for (int i = 0; i < q; i++) {
        cin >> power[i];
        vector<int>::iterator it;
        it = upper_bound(begin(soldiers), end(soldiers), power[i]);
        int idx = it - soldiers.begin();
        /*if (*it == 0) {
            *it = n;
        }*/
        int sumPower = sum(soldiers, idx);
        cout << idx << " " << sumPower << endl;
    }
    return 0; 
}