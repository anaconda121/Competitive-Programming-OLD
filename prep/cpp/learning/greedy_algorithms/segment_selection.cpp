#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*void setIO(string name = "") { // name is nonempty for USACO file I/O
    ios_base::sync_with_stdio(0); cin.tie(0); // see Fast Input & Output
    // alternatively, cin.tie(0)->sync_with_stdio(0);
    freopen((name+".in").c_str(), "r", stdin); // see Input & Output
    freopen((name+".out").c_str(), "w", stdout);
}*/

bool cmp(pair<int,int> a, pair<int,int> b) {
    if (a.second != b.second) {
        return a.second < b.second;
    } 
    return a.first < b.first;
}

int main() {
    //setIO("segment");
    int n;
    cin >> n;
    vector<pair<int,int>> c (n);
    for (int i = 0; i < n; i++) {
        cin >> c[i].first >> c[i].second;
    }
    //sorting segments by their ending value (least-greatest)
    sort(begin(c), end(c), cmp);
    int count = 1;
    int i = 0; //index counter for lastest segment added
    for (int j = 1; j < n; j++) {
        if (c[j].first >= c[i].second) {
            // 2 segments don't overlap, c[j] is now the lastest segment added
            count++;
            i = j; //update counter since count++
        }
    }
    cout << count << endl;
    return 0;
}