#include <bits/stdc++.h>

using namespace std;

#define maxn 100005

int n, m, cc;
int components[maxn];
string s;
char pref[maxn];
vector<int> adj[maxn];

void setIO(string name, bool includeout=false) { // name is nonempty for USACO file I/O
    ios_base::sync_with_stdio(0); cin.tie(0); // see Fast Input & Output
    // alternatively, cin.tie(0)->sync_with_stdio(0);
    freopen((name+".in").c_str(), "r", stdin); // see Input & Output
    if (includeout) {
        freopen((name+".out").c_str(), "w", stdout);
    }
}

void dfs(int start) {
    if (components[start]) {
        return;
    }
    components[start] = cc; //assign component #
    for (auto next : adj[start]) {
        if (pref[start] == pref[next]) {
            dfs(next);
        }
    }
}

int main() {
    setIO("milkvisits", true);
    string ans = "";
    cin >> n >> m;
    cin >> s;
    for (int i = 1; i < n+1; i++) {
        pref[i] = s[i-1];
    }
    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 1; i < n+1; i++) if (!components[i]) {
        //add new component
        cc++;
        dfs(i);
    }
    
    for (int i = 0; i < m; i++) {
        int a, b;
        char c;
        cin >> a >> b >> c;
        if ((components[a] == components[b] && pref[a] == c) || components[a] != components[b]) {
            //cout << pref[a] << " " << pref[b] << " " << c << endl;
            ans += '1';
        } else {
            ans += '0';
        }
    }
    cout << ans << endl;
    return 0;
}