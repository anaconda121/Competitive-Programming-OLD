#include <algorithm>
#include <vector>
#include <math.h>
#include <iostream>
#include <cstring>

using namespace std;

#define maxn 5005

int n, q;
int currK, start;
vector<pair<int,int>> adj[maxn];
bool visited[maxn];
int ans = 0;

void setIO(string name, bool includeout=false) { // name is nonempty for USACO file I/O
    ios_base::sync_with_stdio(0); cin.tie(0); // see Fast Input & Output
    // alternatively, cin.tie(0)->sync_with_stdio(0);
    freopen((name+".in").c_str(), "r", stdin); // see Input & Output
    if (includeout) {
        freopen((name+".out").c_str(), "w", stdout);
    }
}

void dfs(int start) {
    if (visited[start] == true) {
        return;
    }
    visited[start] = true;
    for (auto next : adj[start]) {
        if (!visited[next.first]) {
            if (next.second < currK) {
                continue;
            }
            ans++;
            dfs(next.first);
        }
    }
}

int main(){
    setIO("mootube", true);
    cin >> n >> q;
    for (int i = 0; i < n-1; i++) {
        int a, b, c;
        cin >> a >> b >> c; 
        adj[a].push_back(make_pair(b,c));
        adj[b].push_back(make_pair(a,c));
    }
    for (int i = 0; i < q; i++) {
        cin >> currK >> start; 
        dfs(start);
        cout << ans << endl;
        ans = 0;
        currK = 0;
        memset(visited, false, sizeof(visited));
    }
    return 0;
}