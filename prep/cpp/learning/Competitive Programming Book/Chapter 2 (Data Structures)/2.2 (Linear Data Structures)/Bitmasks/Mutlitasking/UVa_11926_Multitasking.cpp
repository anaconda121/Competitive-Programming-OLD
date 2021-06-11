#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

void setIO(string name = "", bool includeout = false) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((name+".in").c_str(), "r", stdin);
    if (includeout)
        freopen((name+".out").c_str(), "w", stdout);
}
#define maxn 1000001
int n, m;
bitset<maxn> bit;

/*
use bitset inside of bool arr
*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    setIO("multi");
    while(cin >> n >> m, n || m) {
        bit.reset();
        bool ok = true;
        for (int i = 0; i < n; i++) {
            if (!ok){
                continue;
            }
            int a, b;
            cin >> a >> b;
            for (int j = a; j < b; j++) {
                if (bit.test(j) == 1) {
                    ok = false;
                } else {
                    bit.set(j);
                }
            }
        }
        for (int j = 0; j < m; j++) {
            if (!ok){
                continue;
            }
            int s, e, c;
            cin >> s >> e >> c;
            bool notDed = true;
            while (notDed && ok) {
                for (int k = s; k < e; k++) {
                    if (k >= maxn){
                        notDed = false;
                        break;
                    } else if (bit.test(k) == 1) {
                        ok = false;
                        break;
                    } else {
                        bit.set(k);
                    }
                }
                s += c;
                e += c;
            }
        }
        if (ok){
            //cout << n << " " << m << endl;
            cout << "NO CONFLICT" << endl;
        } else {
            //cout << n << " " << m << endl;
            cout << "CONFLICT" << endl;
        }
        
    }
    return 0;
}
