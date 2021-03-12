#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define f first
#define s second
#define maxn 1005

int adjList[maxn];
int visited[maxn] = {0};
int n;

void dfs(int src) {
    if (visited[src]) {
        cout << src + 1 << " ";
        return;
    }
    visited[src] = true;
    dfs(adjList[src]);
}

int main(){
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        a--;
        adjList[i] = a;
    }
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < n; i++) {
        memset(visited, false, sizeof(visited));
        dfs(i);
    }
    return 0;
}