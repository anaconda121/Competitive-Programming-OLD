#include <bits/stdc++.h>

using namespace std;

#define ll long 
#define maxn 505

int n;
bool mat1[maxn][maxn];
bool mat2[maxn][maxn];

void setIO(string name, bool includeout=false) { 
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((name+".in").c_str(), "r", stdin); 
    if (includeout) {
        freopen((name+".out").c_str(), "w", stdout);
    }
}

ll solve(bool b[maxn][maxn]) {
    int a[maxn][maxn];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = b[i][j];
        }
    }

    ll res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == 1) {
                if (i > 0 && j > 0) {
                    a[i][j] = 1 + min(min(a[i - 1][j], a[i][j - 1]), a[i - 1][j - 1]);
                }
            }
            res += a[i][j];
        }
    }
    return res;
}

int main(){
    setIO("3");
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    //cout << n << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int num;
            cin >> num;
            if (num >= 100) {
                mat1[i][j] = true;
            }
            if (num > 100) {
                mat2[i][j] = true;
            }
        }
    }
    //printMat(mat1);
    //cout << "\n";
    //printMat(mat2);
    ll ans1 = solve(mat1);
    ll ans2 = solve(mat2);
    cout << ans1 << endl;
    cout << ans2 << endl;
    cout << ans1 - ans2 << endl;
    return 0;
}