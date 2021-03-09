#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define pb push_back
#define f first
#define s second
#define maxn 100005
 
int n, m;
vector<int> adj[maxn];
int ans[maxn];
vector<int> color(maxn, -1);
 
bool isBipartite(int node) {
    queue<int> q;
    q.push(node);
    color[node] = 0;
    //Process current graph component using BFS
    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        for(int ele : adj[curr]) {
            if(color[ele]==color[curr]) 
                //odd-cycle found
                return false;
            if(color[ele]==-1) {
                //unvisited node
                color[ele] = 1-color[curr];
                q.push(ele);
                ans[ele] = color[ele];            
                //cout << ele << " " << ans[ele] << endl;
            }
        }
    }
    return true;
}
 
int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
 
    bool bipartite = true;
    for(int i=0; i < n; ++i) {
        if(color[i]==-1) {
            if(!isBipartite(i)) {
                bipartite = false;
                break;
            }
        }
    }
 
    if (!bipartite) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        for (int i = 0; i < n; i++) {
            cout << ans[i]+1 << " ";
        }
        cout << endl;
    }
    return 0; 
}