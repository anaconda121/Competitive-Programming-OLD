#include <algorithm>
#include <vector>
#include <math.h>
#include <iostream>

using namespace std;

#define maxn 100005

int n, m, maija;
int start = 1;
vector<int> adj[maxn];
bool visited[maxn];
int len = 0;

void dfs(int start) {
    if (visited[start] == true) {
        return;
    }
    visited[start] = true;
    for (auto next : adj[start]) {
        if (!visited[next]) {
            len++;
            dfs(next);
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    maija = n;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    return 0;
}