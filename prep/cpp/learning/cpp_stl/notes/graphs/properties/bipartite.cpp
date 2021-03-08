#include <bits/stdc++.h>

using namespace std;

#define N 50 //arbitrary number
vector<int> adj[N+5];
int m; //# nodes

bool isBipartite(int node,vector<int>& color) {
    queue<int> q;
    q.push(node);
    color[node] = 1;
    //Process current graph component using BFS
    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        for(int ele: adj[curr]) {
            if(color[ele]==color[curr]) //Odd-cycle
                return false;
            if(color[ele]==-1) {
                //unvisited node
                color[ele] = 1-color[curr]; // only possible "colors" are 0 and 1. if color[curr] = 0, need color 1. if color[curr] = 1, need color 0
                q.push(ele);
            }
        }
    }
    return true;
}

int main(){
    cin >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> color(N+1, -1);
    for(int i=0; i < N; ++i)
            if(color[i]==-1)
                if(!isBipartite(i,color))
                    cout << "NOT BIPARTITE" << endl;
    cout << "BIPARTITE" << endl;
    return 0;
}