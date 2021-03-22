#include <algorithm>
#include <vector>
#include <math.h>
#include <iostream>
#include <stdio.h>

using namespace std;

using ll = long long;

using vi = vector<int>;
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair


/*
Let's transform the problem by assigning start points the value 1
 and end points the value 1
. Then, if we put the start and end points into an array and sort them, 
the problem becomes: "given an array of values, find the maximum sum at some prefix in the array." 
This can be done by looping over the array and storing a running sum.
*/
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<pi> vals;
    for (int i = 0; i < n; i++) {
        int l, r; 
        cin >> l >> r;
        vals.pb(mp(l, 1));
        vals.pb(mp(r, -1));
    }

    sort(all(vals)); 

    int sum = 0;
    int ans = 0;
    for (auto x : vals) {
        sum += x.s;
        ans = max(ans, sum);
    }
    cout << ans << '\n';
}