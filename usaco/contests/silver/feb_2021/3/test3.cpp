#include <bits/stdc++.h>

using namespace std;

int M[1000][1000][10][10];
int **matrix;

void precompute_max(){
    for (int i = 0 ; (1<<i) <= n; i += 1){
        for(int j = 0 ; (1<<j) <= m ; j += 1){
            for (int x = 0 ; x + (1<<i) -1 < n; x+= 1){
                for (int y = 0 ;  y + (1<<j) -1 < m; y+= 1){
                    if (i == 0 and j == 0)
                        M[x][y][i][j] = matrix[x][y]; // store x, y
                    else if (i == 0)
                        M[x][y][i][j] = max(M[x][y][i][j-1], M[x][y+(1<<(j-1))][i][j-1]);
                    else if (j == 0)
                        M[x][y][i][j] = max(M[x][y][i-1][j], M[x+ (1<<(i-1))][y][i-1][j]);
                    else 
                        M[x][y][i][j] = max(M[x][y][i-1][j-1], M[x + (1<<(i-1))][y][i-1][j-1], M[x][y+(1<<(j-1))][i-1][j-1], M[x + (1<<(i-1))][y+(1<<(j-1))][i-1][j-1]);
                    // cout << "from i="<<x<<" j="<<y<<" of length="<<(1<<i)<<" and length="<<(1<<j) <<"max is: " << M[x][y][i][j] << endl;
                }
            }
        }
    }
}

int compute_max(int x, int y, int x1, int y1){
    int k = log2(x1 - x + 1);
    int l = log2(y1 - y + 1);
    // cout << "Value of k="<<k<<" l="<<l<<endl;
    int ans = max(M[x][y][k][l], M[x1 - (1<<k) + 1][y][k][l], M[x][y1 - (1<<l) + 1][k][l], M[x1 - (1<<k) + 1][y1 - (1<<l) + 1][k][l]);
    return ans;
}

void setIO(string name, bool includeout=false) { // name is nonempty for USACO file I/O
    ios_base::sync_with_stdio(0); cin.tie(0); // see Fast Input & Output
    // alternatively, cin.tie(0)->sync_with_stdio(0);
    freopen((name+".in").c_str(), "r", stdin); // see Input & Output
    if (includeout) {
        freopen((name+".out").c_str(), "w", stdout);
    }
}

int main(){
    setIO("test");
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> matrix[i][j];
        }
    }
    cout << compute_max(1,1,2,2) << endl;
    return 0;
}