#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define f first
#define s second

void setIO(string name = "", bool includeout = false) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((name+".in").c_str(), "r", stdin);
    if (includeout)
        freopen((name+".out").c_str(), "w", stdout);
}

int players[1024];
int storage[1024];

int main() {
    //setIO("jolly");
    int t;
    cin >> t;
    while(t--) {
        int ret = 0;
        int n,m;
        cin >> n >> m;
        int evals = 1 << n;
        memset(players, 0, sizeof(players));
        for (int i = 0; i < m; i++){
            int x;
            cin >> x;
            players[x-1]=1;
        }
        for (int i = 0; i < n; i++) {
            memset(storage, 0, sizeof(storage));
            evals >>= 1;
            for (int j = 0; j < evals; j++) {
                if (players[j << 1] ^ players[(j << 1) + 1]) {
                    //cout << (j << 1) << " " << (j << 1) + 1 << endl;
                    ret++;
                }
                storage[j] = (players[j << 1] & players[(j << 1)+1]);
            }
            memcpy(players, storage, sizeof(storage));
        }
        
        cout << ret << endl;
    }
}
