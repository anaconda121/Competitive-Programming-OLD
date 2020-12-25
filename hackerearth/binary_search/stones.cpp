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

int main() {
    setIO("stones");
    int n;
    cin >> n;
    vector<int> stones (n);
    for (int i = 0; i < n; i++) {
        int s;
        cin >> s;
        stones[i] = s;
        if (i > 0) {
            stones[i] += stones[i-1];
        }
    }
    sort(begin(stones), end(stones));

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int qcount;
        cin >> qcount;
        vector<int>::iterator it;
        it = lower_bound(begin(stones), end(stones), stones[n-1]-qcount);
        int idx = it - begin(stones);
        if (*it == 0) {
            idx = n-1;
        }
        if (idx % 2 == 0) {
            cout << "A" << endl;
        } else {
            cout << "B"<< endl;
        }
    }
    return 0;
}