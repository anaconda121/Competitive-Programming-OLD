// http://www.usaco.org/index.php?page=viewproblem2&cpid=944

/* 
find minx, miny, maxx, maxy in each connected component (aka moonet)
use those for perimeter, find min perimeter
*/

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vi vector<int>
#define pi pair<int,int>
#define pb push_back
#define maxn 100005

int n,m;
pair<ll,ll> coords[maxn];
vector<int> adj[maxn];
bool visited[maxn];
ll maxX = 0;
ll maxY = 0;
ll minX = 0;
ll minY = 0;
ll perimeter = INT_MAX;

void setIO(string name, bool includeout=false) { // name is nonempty for USACO file I/O
    ios_base::sync_with_stdio(0); cin.tie(0); // see Fast Input & Output
    // alternatively, cin.tie(0)->sync_with_stdio(0);
    freopen((name+".in").c_str(), "r", stdin); // see Input & Output
    if (includeout) {
        freopen((name+".out").c_str(), "w", stdout);
    }
}

void calc(int x) {
    minX = min(minX, coords[x].first);
    minY = min(minY, coords[x].second);
    maxX = max(maxX, coords[x].first);
    maxY = max(maxY, coords[x].second);
}

void dfs(int start) {
    if (visited[start] == true) {
        return;
    }
    visited[start] = true;
    calc(start);
    for (auto next : adj[start]) {
        if (!visited[next]) {
            calc(next);
            dfs(next);
        }
    }
}

ll countComponents(){
    for (int i = 0; i < n; i++) {
        minX = minY = INT_MAX;
        maxX = maxY = INT_MIN;
        if(!visited[i]) {
            dfs(i);
            ll x = maxX - minX;
            ll y = maxY - minY;
            //cout << 2*x+2*y << " , " << minX << " " << minY << " " << maxX << " " << maxY << endl;
            perimeter = min(perimeter, 2*x + 2*y);
        }
    }
    return perimeter;
}

int main() {
    setIO("fenceplan", true);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> coords[i].first >> coords[i].second;
    }
    for (int i = 0; i < m; i++) {
        ll a,b;
        cin >> a >> b;
        a--; b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    cout << countComponents() << endl;
    return 0;
}