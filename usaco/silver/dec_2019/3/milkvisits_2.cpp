#include <bits/stdc++.h>

using namespace std;

#define maxn 100005

int n, m;
string pref;
bool visited[maxn];
vector<pair<int, char>> adj[maxn];
char type;

void dfs(int start, char t) {
    if (visited[start] == true) {
        return;
    }
    visited[start] = true;
    for (auto next : adj[start]) {
        if (!visited[next.first] && adj[start][next.second] == t) {
            
            dfs(next);
        }
    }
}

int main() {
    cin >> n >> m >> pref;
    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(make_pair(b, pref[b]));
        adj[b].push_back(make_pair(a, pref[a]));
    }
    type = 'H';
    for (int i = 0; i < n; i++) {
        dfs(i, type)
    }
    type = 'G';
    for (int i = 0; i < n; i++) {
        dfs(i, type)
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        char c;
        cin >> a >> b >> c;
    }
    return 0;
}