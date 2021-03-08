#include <bits/stdc++.h>

using namespace std;

#define maxn 1005 //placeholder value, depends on problem statement
vector<int> adj[maxn];
int n;

void dfs(int start) {
    if (visited[start] == true) {
        return;
    }
    visited[start] = true;
    for (auto next : adj[start]) {
        if (!visited[next]) {
            dfs(next);
        }
    }
}

int countComponents(){
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i);
            count++;
        }
    }
    return count;
}

int main(){
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a,b;
        cin >> a >> b;
        a--; b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    cout << countComponents() << endl;
    return 0;
}