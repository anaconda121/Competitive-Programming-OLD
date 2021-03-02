#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

void setIO(string name = "") { // name is nonempty for USACO file I/O
    ios_base::sync_with_stdio(0); cin.tie(0); // see Fast Input & Output
    // alternatively, cin.tie(0)->sync_with_stdio(0);
    freopen((name+".in").c_str(), "r", stdin); // see Input & Output
    freopen((name+".out").c_str(), "w", stdout);
}

bool cmp(pair<int,int> a, pair<int,int> b) {
    if (a.first != b.first) {
        return a.first < b.first;
    } 
    return a.second < b.second;
}

pair<int,int> calcDist(vector<pair<int,int>> a, int i) {
    vector<pair<int,int>> b = a;
    sort(begin(b), end(b), cmp);
    //for (auto element : b) {
    //    cout << element.first << " , " << element.second << endl;
    //}
    pair<int,int> idxs = make_pair(0, i);
    auto it = find(begin(a), end(a), make_pair(b[idxs.first].first, b[idxs.first].second));
    auto it2 = find(begin(a), end(a), make_pair(b[idxs.second].first, b[idxs.second].second));
    cout << it->first << " , " << it->second << " , it" << "\n";
    cout << it2->first << " , " << it2->second << " , it2" << "\n";
    if (it-begin(a) + 1 > it2 - begin(a)+1) {
        return make_pair(it2-begin(a) + 1, it - begin(a)+1);
    }
    return make_pair(it-begin(a) + 1, it2 - begin(a)+1);
}

int main() {
    setIO("dist");
    int n;
    cin >> n;
    vector<pair<int,int>> c;
    for (int i = 0; i < n; i++) {
        pair<int,int> x;
        int a, b;
        cin >> a >> b;
        c.push_back(make_pair(a,b));
        x = calcDist(c,i);
        //cout << x.first << " , " << x.second << endl;
    }

    vector<pair<int,int>> ans (n);

    return 0;
}