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

bool coin[1005];
int m;
int n,k, p;
int lefte[55]; int righte[55];
char sign;

int findFalse(){
    vector<int> bad;
    for (int i = 1; i <= n; i++){
        if (!coin[i]) {
            bad.pb(i);
        }
    }
    for (auto x : bad) {
        cout << x << " , ";
    }
    cout << endl;
    if (bad.size() == 1) {
        return bad[0];
    }
    return 0;
}

int main() {
    setIO("coin");
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> n >> k;
        for (int j = 0; j < 2*k; j++) {
            if (j % 2 == 0) {
                memset(lefte, 0, sizeof(lefte));
                memset(righte, 0, sizeof(righte));
                if (j == 1) {
                    string line;
                    cin >> line;
                    cout << line << endl;
                }

                cin >> p;
                cout << "p: " << p << endl;
                for (int l = 1; l <= 2*p; l++) {
                    int x; 
                    cin >> x;
                    if (l <= p){
                        cout << "assigning left vals "  << x << endl;
                        lefte[l] = x;
                    } else {
                        cout << "assigning right vals " << x << endl;
                        righte[l-p] = x;
                    }
                }   
                cout << "Left: ";
                for (int g = 1; g <= p; g++) {
                    cout << lefte[g] << " , ";
                }
                cout << endl;
                cout << "Right: ";
                for (int rr = 1;rr <= p; rr++) {
                    cout << righte[rr] << " , ";
                }
                cout << endl;
            }

            
            cin >> sign;
            if (sign == '<') {
                for (int o = 1; o <= p; o++) {
                    coin[lefte[o]] = true;
                }
            } else if (sign == '>') {
                for (int o = 1; o <= p; o++) {
                    coin[righte[o]] = true;
                }
            } else if (sign == '=') {
                for (int o = 1; o <= 2*p; o++) {
                    coin[righte[o]] = true;
                    coin[lefte[o]] = true;
                }
            }

            for (int z = 1; z <= n; z++){
                cout << coin[z] << " , ";
            }
            cout << endl;
        }
        cout << findFalse() << "\n\n";
        memset(coin, false, sizeof(coin));
    }
    return 0;
}
