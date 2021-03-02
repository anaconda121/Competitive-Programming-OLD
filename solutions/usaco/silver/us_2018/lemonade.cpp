#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void setIO(string name = "") { // name is nonempty for USACO file I/O
    ios_base::sync_with_stdio(0); cin.tie(0); // see Fast Input & Output
    // alternatively, cin.tie(0)->sync_with_stdio(0);
    freopen((name+".in").c_str(), "r", stdin); // see Input & Output
    freopen((name+".out").c_str(), "w", stdout);
}

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    setIO("lemonade");
    int n;
    cin >> n;
    vector<int> w (n);
    for (int i = 0; i < n; i++) {
        cin >> w[i]; 
    }
    sort(begin(w), end(w), cmp);
    int stay = 0;
    for (int i = 0; i < n; i++) {
        if (w[i] >= i) {
            stay++;
        }
    }
    cout << stay << endl;
    return 0;
}