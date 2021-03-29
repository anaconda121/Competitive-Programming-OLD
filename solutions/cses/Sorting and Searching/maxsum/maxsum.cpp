//find max diff. btwn. prefix sum values

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

int main() {
    //setIO("maxsum");
    int n;
    cin >> n;
    vector<ll> nums (n+1);
    vector<int> psum (n+1);
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        nums[i] += nums[i-1] + a;
    }
    ll maxe = INT_MIN; ll mine = nums[0];
    for (int i = 1; i <= n; i++) {
        maxe = max(maxe, nums[i] - mine);
        mine = min(mine, nums[i]);
        //cout << maxe << " " << mine << " " << i << endl;
    }
    // cout << nums[n] << endl;
    // if (maxe == nums[n]) {
    //     cout << maxe - mine << endl;
    // } else {
   // }
    cout << maxe << endl;
    return 0;
}
