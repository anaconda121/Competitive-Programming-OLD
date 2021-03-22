//http://www.usaco.org/index.php?page=viewproblem2&cpid=896

/*
base coords can be found with (x-y, 0) & (x+y, 0)
create segments with the bases and find the segments that dont get overlapped by anyone
*/

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define f first
#define s second

void setIO(string name = "", bool includeout = false) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((name+".in").c_str(), "r", stdin);
    if (includeout)
        freopen((name+".out").c_str(), "w", stdout);
}

vector<pair<int,int>> segments;
int n;

bool cmp (pair<int,int> a, pair<int,int> b) {
    if (a.f == b.f) {
        return a.s > b.s;
    }
    return a.f < b.f;
}

int main() {
    setIO("mountains", true);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        segments.pb({a-b, a+b});
    }
    sort(segments.begin(), segments.end(), cmp);
    int rightMostCoord = INT_MIN;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (segments[i].s > rightMostCoord) {
            ans++;
            rightMostCoord = segments[i].s;
        }
    }
    cout << ans << endl;
    return 0;
}
