#include <bits/stdc++.h>

using namespace std;

const int Nmax = 101;
const int Mmax = 101;

int a[Nmax][Mmax], n, m;
long long UpSum[Nmax][Mmax]; /// UpSum[i][j] = a[1][j] + a[2][j] + ... + a[i][j]
/// UpSum[i][j] = UpSum[i - 1][j] + a[i][j];

void setIO(string name, bool includeout=false) { // name is nonempty for USACO file I/O
    ios_base::sync_with_stdio(0); cin.tie(0); // see Fast Input & Output
    // alternatively, cin.tie(0)->sync_with_stdio(0);
    freopen((name+".in").c_str(), "r", stdin); // see Input & Output
    if (includeout) {
        freopen((name+".out").c_str(), "w", stdout);
    }
}

long long maxSumSubarray(long long a[], int n) {
    long long ans = INT_MAX;
    //cout << n << " n " << endl;
    for(int i = 1; i <= n; i++) {
        cout << a[i] << " a[i] " << endl;
        if (a[i] != 0) {
            ans = min(ans, a[i]);
        }
    }
    return ans;
}

long long maxSumSubmatrix() {
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            UpSum[i][j] = UpSum[i - 1][j] + a[i][j];

    long long v[Mmax]; /// v[i] = a[r1][i] + a[r1+1][i] + ... + a[r2][i]
    long long ans = 0;//a[1][1];
    long long count = 0;
    for(int r1 = 1; r1 <= n; r1++)
        for(int r2 = r1; r2 <= n; r2++) {
            for(int i = 1; i <= n; i++)
                v[i] = UpSum[r2][i] - UpSum[r1 - 1][i];

            for (long long a : v) {
                cout << a << " , ";
            }
            cout << endl;
            ans = maxSumSubarray(v, n);
            //cout << ans << " ans " << endl;
            if (ans == 100) {
                count++;
            }
        }
    return count;
}

int main()
{
    setIO("3");
    cin >> n ;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> a[i][j];
    // for(int i = 1; i <= n; i++)
    //     for(int j = 1; j <= n; j++)
    //         cout << a[i][j] << " , ";
    //     cout << "\n";
    cout << maxSumSubmatrix();
    return 0;
}