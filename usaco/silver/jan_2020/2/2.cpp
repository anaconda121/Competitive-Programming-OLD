#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vi vector<int>;
#define pi pair<int,int>;
#define sz(x) (int)(x).size()
#define pb push_back
#define all(x) begin(x), end(x)
#define f first
#define s second

ll n, m, k;

void setIO(string name, bool includeout=false) { // name is nonempty for USACO file I/O
    ios_base::sync_with_stdio(0); cin.tie(0); // see Fast Input & Output
    // alternatively, cin.tie(0)->sync_with_stdio(0);
    freopen((name+".in").c_str(), "r", stdin); // see Input & Output
    if (includeout) {
        freopen((name+".out").c_str(), "w", stdout);
    }
}

bool check (ll x) {
    ll given = 0;
    ll total = 0;
    for (ll i = 0; i < k; i++) {
        ll y = (n - given) / x;
        //cout << y << " y " << endl;
        if (y < m) {
            y = m;
        }
        given += y;
        total += y;
    }
    //cout << total << " tot" << endl;
    return (total >= n);
}

int main() {
    setIO("loan", true);
    cin >> n >> k >> m;
    ll lo = 1; ll hi = (ll)1e12 + 5;
    while (lo + 1 < hi) {
        ll mid = lo+(hi-lo+1)/2;
        if (check(mid)) {
            lo = mid;
        } else {
            hi = mid-1;
        }
    }
    cout << lo << endl;
    return 0;
}