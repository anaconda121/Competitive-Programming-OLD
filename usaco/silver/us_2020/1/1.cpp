#include <bits/stdc++.h>

using namespace std;

#define ll long long

int n, m;
ll maxe = 0;
ll cowsIncluded = 0;
ll ans = INT_MAX;
vector<pair<ll,ll>> intervals;
vector<tuple<ll,ll,ll>> gaps;

void setIO(string name, bool includeout=false) { // name is nonempty for USACO file I/O
    ios_base::sync_with_stdio(0); cin.tie(0); // see Fast Input & Output
    // alternatively, cin.tie(0)->sync_with_stdio(0);
    freopen((name+".in").c_str(), "r", stdin); // see Input & Output
    if (includeout) {
        freopen((name+".out").c_str(), "w", stdout);
    }
}

bool cmp (tuple<ll,ll,ll> &a, tuple<ll,ll,ll> &b) {
    return (get<2>(a) > get<2>(b));
}

int main() {
    setIO("socdist");
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        ll a,b;
        cin >> a >> b;
        intervals.push_back(make_pair(a, b));
        maxe = max(maxe, max(a,b));
    }
    //int line[maxe+1];
    for (int i = 0; i < m; i++) {
        ll a = intervals[i].first;
        ll b = intervals[i].second;
        // line[a] = 1;
        // line[b] = 1;
        if (a != b) {
            cowsIncluded += 2;
        } else {
            cowsIncluded++;
        }
        gaps.push_back(make_tuple(a, b, b-a));
        if (a != b) {
            ans = min(ans, b-a);
        }
    }
    sort(gaps.begin(), gaps.end(), cmp);
    // for (auto x : gaps) {
    //     cout << get<0>(x) << " , " << get<1>(x) << " , " << get<2>(x) << endl;
    // }
    cout << cowsIncluded << " " << n << endl;

    ll idx = 0;
    while (cowsIncluded < n) {
        //cout << idx % n << " " << idx << " " << n << " " << endl;
        ll a = get<0>(gaps[idx % n]);
        ll b = get<1>(gaps[idx % n]);
        ll mid = (a+b)/2;
        // line[mid] = 1;
        ans = min(ans, min(mid-a, b-mid));
        if (mid-a > b-mid) {
            get<1>(gaps[idx % n]) = mid;
        } else {
            get<0>(gaps[idx % n]) = mid;
        }
        idx++;
        cowsIncluded++;
        cout << ans << endl;
    }
    return 0;
}