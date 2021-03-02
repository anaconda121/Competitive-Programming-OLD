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

pair<int,int> calcMaxDist(vector<int> a, int i) {
    vector<int> b = a;
    sort(begin(b), end(b));
    pair<int,int> idxs = make_pair(0, i);
    auto it = find(begin(a), end(a), b[idxs.first]);
    auto it2 = find(begin(a), end(a), b[idxs.second]);
    if (it-begin(a) + 1 > it2 - begin(a)+1) {
        return make_pair(it2-begin(a) + 1, it - begin(a)+1);
    }
    return make_pair(it-begin(a) + 1, it2 - begin(a)+1);
}

int main() {
    setIO("dist");
    int n;
    cin >> n;
    vector<int> num;
    for (int i = 0; i < n; i++) {
        pair<int,int> ans;
        int a;
        cin >> a;
        num.push_back(a);
        ans = calcMaxDist(num, i);
        cout << ans.first << " " << ans.second << endl;
    }
}