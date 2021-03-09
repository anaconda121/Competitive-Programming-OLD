//https://codeforces.com/contest/862/problem/B
// max num of edges in bipartite graph: zeroCount * oneCount
// currentEdges = n-1
// (zeroCount * oneCount ) - (n-1) = ANS

#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define pb push_back
#define f first
#define s second
#define maxn 100005

int n;
vector<int> adj[maxn];
vector<int> color(maxn, -1);
long long zeroCount = 0;
long long oneCount = 0;

void setIO(string name, bool includeout=false) { // name is nonempty for USACO file I/O
    ios_base::sync_with_stdio(0); cin.tie(0); // see Fast Input & Output
    // alternatively, cin.tie(0)->sync_with_stdio(0);
    freopen((name+".in").c_str(), "r", stdin); // see Input & Output
    if (includeout) {
        freopen((name+".out").c_str(), "w", stdout);
    }
}

void colorGraph(int node) {
    queue<int> q;
    q.push(node);
    color[node] = 0;
    if (node == 1) zeroCount++;
    //Process current graph component using BFS
    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        for(int ele : adj[curr]) {
            if(color[ele]==-1) {
                //unvisited node
                color[ele] = 1-color[curr];
                color[ele] == 0 ? zeroCount++ : oneCount++;
                q.push(ele);
            }
        }
    }
}

int main(){
    //setIO("B");
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    colorGraph(1);
    cout << zeroCount * oneCount  - (n-1) << endl;
    return 0;
}