#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vi vector<int>
#define pi pair<int,int>
#define sz(x) (int)(x).size()
#define pb push_back
#define f first
#define s second

int n, k;
ll maxPos = 0;
vector<int> pos;

void setIO(string name, bool includeout=false) { // name is nonempty for USACO file I/O
    ios_base::sync_with_stdio(0); cin.tie(0); // see Fast Input & Output
    // alternatively, cin.tie(0)->sync_with_stdio(0);
    freopen((name+".in").c_str(), "r", stdin); // see Input & Output
    if (includeout) {
        freopen((name+".out").c_str(), "w", stdout);
    }
}

bool check(ll r) {
    ll idx = 0;
    ll end = 0;
    for (int i = 0; i < k; i++) {
        ll placed = pos[idx] + r;
        end = placed + r;
        if (end >= maxPos) {
            return true;
        }
        auto val = upper_bound(pos.begin(), pos.end(), end);
        idx = val - pos.begin();
    }
    return (end >= maxPos);
}

int main() {
    setIO("angry", true);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        ll a;
        cin >> a;
        maxPos = max(maxPos, a);
        pos.pb(a);
    }
    sort(pos.begin(), pos.end());
    ll lo = 1; ll hi = 1e9 + 5;
    ll ans = 1e9 + 5;
    while (lo <= hi) {
        ll mid = lo+(hi-lo)/2;
        if (check(mid)) {
            ans= min(ans, mid);
            hi = mid-1;
        } else {
            lo = mid+1;
        }
    }
    cout << ans << endl;
    return 0;
}