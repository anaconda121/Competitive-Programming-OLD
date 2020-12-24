#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <climits>

using namespace std;

void setIO(string name = "") { // name is nonempty for USACO file I/O
    ios_base::sync_with_stdio(0); cin.tie(0); // see Fast Input & Output
    // alternatively, cin.tie(0)->sync_with_stdio(0);
    freopen((name+".in").c_str(), "r", stdin); // see Input & Output
    freopen((name+".out").c_str(), "w", stdout);
}

bool cmp(pair<int,int> p, pair<int,int> p2) {
    return p.first < p2.first;
}

int main() {
    setIO("lifeguards");
    int N;
    vector<pair<int,int>> v;
    cin >> N;
    for (int i = 0; i < N; i++) {
        pair<int,int> curr;
        cin >> curr.first >> curr.second;
        v.push_back(curr);
    }
    int minShift = INT_MAX; 
    sort(begin(v), end(v), cmp);
    int totalTime = 0;
    for (int i = 0; i < N; i++) {
        int curr = 0;
        curr = v[i].second-v[i].first;
        if (i > 0 && i < N-1) {
            if (v[i-1].second > v[i].first) {
                curr -= (v[i-1].second - v[i].first);
            } else if (v[i].second > v[i+1].first) {
                curr -= v[i].second - v[i+1].first;
            }
        } 
        if (curr < 0) {
            curr = 0;
        }
        minShift = min(minShift, curr);
        totalTime += curr;
        //cout << curr << " " << totalTime << endl;
    }
    cout << totalTime - minShift << endl;
    return 0;
}