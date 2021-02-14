#include <bits/stdc++.h>

using namespace std;

#define ll long long

int n, m;
pair<ll,ll> intervals[100005];

void setIO(string name, bool includeout=false) { // name is nonempty for USACO file I/O
    ios_base::sync_with_stdio(0); cin.tie(0); // see Fast Input & Output
    // alternatively, cin.tie(0)->sync_with_stdio(0);
    freopen((name+".in").c_str(), "r", stdin); // see Input & Output
    if (includeout) {
        freopen((name+".out").c_str(), "w", stdout);
    }
}

bool check(long long dist) {
    long long currPoint = intervals[0].first;
    long long currInterval = 0;
    for (int i = 1; i < n; i++) {
        currPoint += dist;
        while (currInterval < m && currPoint > intervals[currInterval].second) {
            currInterval++;
        }
        if (currInterval == m) {
            return false;
        }
        if (intervals[currInterval].first > currPoint) {
            currPoint = intervals[currInterval].first;
        }
    }
    return true;
}

int main() {
    setIO("socdist");
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> intervals[i].first >> intervals[i].second;
    }
    sort(intervals, intervals + m);
    long long lo = 1; long long hi = pow(10, 18) + 5;
    while (lo + 1 < hi) {
        long long mid = (lo + hi) / 2;
        if (check(mid)) {
            lo = mid;
        } else {
            hi = mid;
        }
    }
    cout << lo << endl;
    return 0;
}