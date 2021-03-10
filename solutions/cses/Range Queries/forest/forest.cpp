//https://cses.fi/problemset/result/1817643/ - basic psums

#include <bits/stdc++.h>

using namespace std;

#define maxn 1005
int n, q;
int forest[maxn][maxn];
int prefix[maxn][maxn];

void setIO(string name, bool includeout=false) { // name is nonempty for USACO file I/O
    ios_base::sync_with_stdio(0); cin.tie(0); // see Fast Input & Output
    // alternatively, cin.tie(0)->sync_with_stdio(0);
    freopen((name+".in").c_str(), "r", stdin); // see Input & Output
    if (includeout) {
        freopen((name+".out").c_str(), "w", stdout);
    }
}

int main(){
    //setIO("forest");
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            char a;
            cin >> a;
            if (a == '*') {
                forest[i][j]++;       
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1] + forest[i][j];
        }
    }
    for (int i = 0; i < q; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        // a --> x1
        // A --> x2
        // b --> y1
        // B --> y2
        long long ans = prefix[x2][y2]-prefix[x1-1][y2]-prefix[x2][y1-1]+prefix[x1-1][y1-1];
        cout << ans << endl;
    }
    return 0;
}