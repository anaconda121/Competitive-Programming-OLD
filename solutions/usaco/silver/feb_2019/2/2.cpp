//http://www.usaco.org/index.php?page=viewproblem2&cpid=919

/*
LOGic:
very similar to concept used in haybales stacking, just extended to 2d
*/

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define f first
#define s second
#define maxn 1005

int mat[maxn][maxn];
int psum[maxn][maxn];

void setIO(string name = "", bool includeout = false) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((name+".in").c_str(), "r", stdin);
    if (includeout)
        freopen((name+".out").c_str(), "w", stdout);
}

int main() {
    setIO("paintbarn", true);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1++; y1++; x2++; y2++;
        mat[x1][y1]++;
        mat[x2][y2]++;
        mat[x1][y2]--;
        mat[x2][y1]--;
    }
    for (int i = 1; i < maxn; i++) {
        for (int j = 1; j < maxn; j++) {
            psum[i][j] = psum[i-1][j] + psum[i][j-1] - psum[i-1][j-1] + mat[i][j];
        }
    }
    // for (int i = 0; i < 10; i++) {
    //     for (int j = 0; j < 10; j++) {
    //         cout << psum[i][j] << " , ";
    //     }
    //     cout << endl;
    // }
    ll ans = 0;
    for (int i = 1; i < maxn; i++) {
        for (int j = 1; j < maxn; j++) {
            if (psum[i][j] == k){
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
