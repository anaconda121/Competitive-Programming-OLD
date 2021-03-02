#include <bits/stdc++.h>

using namespace std;

#define maxn 1005

void setIO(string name, bool includeout=false) { // name is nonempty for USACO file I/O
    ios_base::sync_with_stdio(0); cin.tie(0); // see Fast Input & Output
    // alternatively, cin.tie(0)->sync_with_stdio(0);
    freopen((name+".in").c_str(), "r", stdin); // see Input & Output
    if (includeout) {
        freopen((name+".out").c_str(), "w", stdout);
    }
}

/* LOGIC
pattern - for any row or colums, the rows must alternate cow then no-cow
E.g. CCCC
     ....
     CCCC
     
     OR
     C.C.C
     .C.C.C
     C.C.C

     OR 
     C.C
     C.C
     C.C
*/

int n;
long long matrix[maxn][maxn];
long long sums[2];
long long vertical = 0;
long long horizontal = 0;
long long ans = 0;

int main() {
    //setIO("3", true);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        sums[0] = 0;
        sums[1] = 0;
        
        for (int j = 0; j < n; j++) {
            sums[j % 2] += matrix[i][j];
        }

        horizontal += max(sums[0], sums[1]);
    }

    for (int i = 0; i < n; i++) {
        sums[0] = 0;
        sums[1] = 0;
        
        for (int j = 0; j < n; j++) {
            sums[j % 2] += matrix[j][i];
        }

        vertical += max(sums[0], sums[1]);
    }

    ans = max(vertical, horizontal);
    cout << ans << endl;
    return 0;
}