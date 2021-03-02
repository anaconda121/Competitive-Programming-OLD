//http://www.usaco.org/index.php?page=viewproblem2&cpid=1038

/*LOGIC
binary search on value of d (pretty much binary search for answer module on usaco.guide)
*/

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
    long long placed = 0;
    while (placed < n) {
        if (intervals[currInterval].first <= currPoint && intervals[currInterval].second >= currPoint) {
            //placed another cow down
            placed++;
            currPoint += dist;
        } else {
            //moving onto next grass patch
            currInterval++;
            if (intervals[currInterval].first >= currPoint) {
                //adjusting currpoint so it can be in correct interval (if needed)
                currPoint = intervals[currInterval].first;
            }
        }
        if (currInterval >= m){
            //placed too many cows down
            return false;
        }
    }
    return true;
}

int main() {
    setIO("socdist", true);
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