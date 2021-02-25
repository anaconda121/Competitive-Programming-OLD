#include <bits/stdc++.h>

using namespace std;

#define maxn 3005

int barns, paths;
bool visited[3005];
vector<int> adj[3005]; //adjacency list
bool deleted[3005];

/*LOGIC
1. check if fully connected for first part (good)
2. keep an bool array of deleted elements
3. when cin >> b, bool[b-1] = true
4. add if (arr[next-1] == false) in dfs
5. add if (arr[i-1] == false) in count
6. keep logic of checking for connected components 
*/

void setIO(string name, bool includeout=false) { // name is nonempty for USACO file I/O
    ios_base::sync_with_stdio(0); cin.tie(0); // see Fast Input & Output
    // alternatively, cin.tie(0)->sync_with_stdio(0);
    freopen((name+".in").c_str(), "r", stdin); // see Input & Output
    if (includeout) {
        freopen((name+".out").c_str(), "w", stdout);
    }
}

void dfs(int start) {
    if (visited[start] == true) return;
    visited[start] = true;
    for (auto next : adj[start]) {
        if (!visited[next] && !deleted[next]) {
            dfs(next);
        }
    }
}

int countComponents(){
    int count = 0;
    for (int i = 0; i < barns; i++) {
        //cout << visited[i] << endl;
        if(!visited[i] && !deleted[i]) {
            count++;
            dfs(i);
        }
    }
    memset(visited, false, sizeof(visited));
    return count;
}

int main(){
    setIO("closing", true);
    cin >> barns >> paths;
    for (int i = 0; i < paths; i++) {
        int a, b;
        cin >> a >> b; 
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int ans = countComponents();
    //cout << ans << endl;
    if (ans == 1) {
        cout << "YES" << endl;
    }
    /*for (int i = 0; i < barns; i++) {
        int count = 0;
        for (int j : adj[i]) {
            if (count < barns) {
                cout << j << " , ";
            }
        }
        cout << "\n";
    }*/
    for (int i = 0; i < barns-1; i++) {
        int b;
        cin >> b; b--;
        //adj[b-1].clear();
        deleted[b] = true;
        int cc = countComponents();
        if (cc == 1) {
            cout << "YES" << endl;
            //cout << "YES" << " " << componets << endl;
        } else {
            cout << "NO" << endl;
            //cout << "NO" << " " << componets << endl;
        }
    }
    return 0;
}