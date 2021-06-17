//https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=606
//have coin arr where they are all false
// if you find one measurement with "=", all the numbers in that measurement are not false
//see if after all measurements only 1 dood is not false
//if only 1 left, that one is false, otherwise 0

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

int m, n, k, p, x;
int lefte[55];
int righte[55];
bool coin[105];
char sign;

int findFalse(){
    vector<int> bad;
    for (int i = 1; i <= n; i++){
        if (!coin[i]) {
            bad.pb(i);
        }
    }
    // cout << "Bad: ";
    // for (auto x : bad) {
    //     cout << x << " , ";
    // }
    //cout << endl;
    if (bad.size() == 1) {
        return bad[0];
    }
    return 0;
}

int main() {
    //setIO("coin");
    cin >> m;
    while(m--){
        cin >> n >> k;
        for (int i = 1; i <= 2*k; i++) {
            if (i % 2 == 1) {
                memset(lefte, 0, sizeof(lefte));
                memset(righte, 0, sizeof(righte));
                cin >> p;
                for (int j = 1; j <= 2*p; j++) {
                    cin >> x;
                    if (j <= p) {
                        lefte[j] = x;
                    } else {
                        righte[j-p] = x;
                    }
                }
                // cout << "Left: ";
                // for (int k = 1; k <= p; k++) {
                //     cout << lefte[k] << " , ";
                // }
                // cout << endl;
                // cout << "Right: ";
                // for (int l = 1; l <= p; l++) {
                //     cout << righte[l] << " , ";
                // }
                // cout << endl;
            } else {
                cin >> sign;
                // cout << "Sign: " << sign << endl;
                // if (sign == '<') {
                //     for (int o = 1; o <= p; o++) {
                //         coin[lefte[o]] = true;
                //         //coin[righte[o]] = false;
                //     }
                // } else if (sign == '>') {
                //     for (int o = 1; o <= p; o++) {
                //         coin[righte[o]] = true;
                //         //coin[lefte[o]] = false;
                //     }
                // } else 
                if (sign == '=') {
                    for (int o = 1; o <= p; o++) {
                        coin[righte[o]] = true;
                        coin[lefte[o]] = true;
                    }
                }
            }
        }
        //cout << "m: " << m << endl;
        if (m >= 1) {
            cout << findFalse() << "\n\n";
        } else {
            cout << findFalse() << endl;
        }
        memset(coin, false, sizeof(coin)); 
    }
    return 0;
}
