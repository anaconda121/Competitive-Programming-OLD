#include <bits/stdc++.h>

using namespace std;

int matrix[4][4];
int prefix[4][4];

int sumOfSubMatrix(int a, int b, int A, int B) {
    int sum = prefix[A][B] - prefix[a-1][B] + prefix[A][b-1] + prefix[a-1][b-1];
    cout << prefix[A][B] << " " << A << " " << B << " " << " | " <<   endl;
    cout << prefix[a-1][B] << " " << a-1 << " " << B << " " <<  endl;
    cout << prefix[A][b-1] << " " << A << " " << b-1 << " " << endl;
    cout << prefix[a-1][b-1] << " " << a-1 << " " << b-1 << " " << endl;
    //cout << matrix[r2][col2] << " , " << matrix[r-1][col2] << " , " << matrix[r2][col-1] << " , " << matrix[r-1][col-1] << endl;
    return sum;
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
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1] + matrix[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << prefix[i][j] << " , ";
        }
        cout << endl;
    }
    cout << "\n\n";
    cout << sumOfSubMatrix(1,1,2,2) << endl;
    return 0;
}