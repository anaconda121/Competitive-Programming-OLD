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

int main() {
    //setIO("__placeholder__", true);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if (a < b) {
            cout << "<" << endl;
        } else if (a > b) {
            cout << ">" << endl;
        } else if (a == b) {
            cout << "=" << endl;
        }
    } 
    return 0;
}
