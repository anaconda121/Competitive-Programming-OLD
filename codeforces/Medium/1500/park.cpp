#include <algorithm>
#include <vector>
#include <math.h>
#include <iostream>
#include <stdio.h>

using namespace std;

int n, catCount;
vector<int> cats;
vector<int> adj[100005];
bool visited[100005];
int res = 0;
int prevNode = 1;

void setIO(string name, bool includeout=false) { // name is nonempty for USACO file I/O
    ios_base::sync_with_stdio(0); cin.tie(0); // see Fast Input & Output
    // alternatively, cin.tie(0)->sync_with_stdio(0);
    freopen((name+".in").c_str(), "r", stdin); // see Input & Output
    if (includeout) {
        freopen((name+".out").c_str(), "w", stdout);
    }
}

void dfs(int start, int count) {
    if (cats[start-1] == 1 && cats[prevNode-1] == 1) {
        count++;
        //cout << count << endl;
    } else {
        count = 0;
    }
    if (visited[start] == true || count > catCount) {
        return;
    }
    visited[start] = true;
    if (adj[start].size() == 1 && start != 1) {
        res++;
    
    } else {
        for (auto next : adj[start]) {
            if (!visited[next]) {
                prevNode = start;
                //cout << prevNode << endl;
                dfs(next, count);
            }
        }
    }
}

int main() {
    //setIO("park", false);
    cin >> n >> catCount;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        cats.push_back(a);
    }
    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 0);

    cout << res << endl;

    return 0;
}