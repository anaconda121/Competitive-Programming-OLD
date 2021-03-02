#include <bits/stdc++.h>

using namespace std;

#define ll long long
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

ll solve(bool arr[maxn][maxn]) { 
    ll p[maxn][maxn] = { 0 };
    //memset(p, sizeof(p[0][0])*maxn*maxn , 0);
    for (int i = 0; i < n; i++) { 
        for (int j = n - 1; j >= 0; j--) { 
            if (!arr[i][j]) 
                continue; 
            if (j != n - 1) 
                p[i][j] += p[i][j + 1]; 
            if (arr[i][j] == true) {
                p[i][j] += 1;
            }
        } 
    } 
    ll ans = 0; 
    for (int j = 0; j < n; j++) { 
        stack<pair<ll, ll> > s; 
        ll to_sum = 0; 
        for (int i = n-1; i >=0; i--) { 
            ll c = 0; 
            while (s.size() != 0 && s.top().first > p[i][j]) { 
                to_sum -= (s.top().second + 1) *  (s.top().first - p[i][j]); 
                c += s.top().second + 1; 
                s.pop(); 
            } 
            to_sum += p[i][j]; 
            ans += to_sum; 
            s.push({p[i][j], c});  
        } 
    } 
    return ans; 
} 

void printMat(bool m[maxn][maxn]){
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << m[i][j] << " , ";
        }
        cout << "\n";
    }
}

int main() {
    //setIO("3");
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
    cout << ans1 - ans2 << endl;
    
    return 0;
}