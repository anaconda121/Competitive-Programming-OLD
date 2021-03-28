#include <bits/stdc++.h>

using namespace std;


int N; //num of edges
vector<int> adj[10001]; //adjacency list
bool visited[10001];

void addEdge(int x, int y) {
    //1. assuming that edge is undirected (bidirectional)
    //2. assuming that values in tree go from 0 - (n-1)
    // creating adj_list
    adj[x].push_back(y); //y is adj to x
    adj[y].push_back(x); //x is adj to y
}

void dfs(int start) {
    if (visited[start] == true) {
        return;
    }
    visited[start] = true;
    for (auto next : adj[start]) {
        if (!visited[next]) {
            //around this area is where some logic will get added that is related to the problem
            //this plain dfs is kinda useless on its own
            dfs(next);
        }
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        addEdge(a,b);
    }
    return 0;
}
