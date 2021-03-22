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

int n;
vector<pair<ll,ll>> times;
ll total = 0;
ll minShift = INT_MAX;

bool cmp (pair<int,int> a, pair<int,int> b) {
    return a.f < b.f;
}

int main(){
    setIO("lifeguards");
    cin >> n;
    for (int i = 0; i < n; i++) {
        int st, t;
        cin >> st >> t;
        if (st == 1) {
            st = 0;
        }
        times.pb({st, t});
    }
    sort(times.begin(), times.end(), cmp);
    for (int i = 0; i < n-1; i++) {
        if (times[i].s > times[i+1].f) {
            times[i+1].f = times[i].s;
        }
    }
    for (int i = 0; i < n; i++) {
        total += times[i].s - times[i].f;
        minShift = min(minShift, times[i].s - times[i].f);
    }
    cout << total - minShift << endl;
    return 0;
}