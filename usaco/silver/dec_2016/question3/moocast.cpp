#include <bits/stdc++.h>

using namespace std;

int n;
int x[205];
int y[205];
int p[205];
vector<int> adj[205];
bool visited[205];
pair<int,int> coords[205];
int currStreak = 0;

void setIO(string name, bool includeout=false) { // name is nonempty for USACO file I/O
    ios_base::sync_with_stdio(0); cin.tie(0); // see Fast Input & Output
    // alternatively, cin.tie(0)->sync_with_stdio(0);
    freopen((name+".in").c_str(), "r", stdin); // see Input & Output
    if (includeout) {
        freopen((name+".out").c_str(), "w", stdout);
    }
}

void dfs(int start) {
    if (visited[start] == true) {
        return;
    }
    visited[start] = true;
    for (auto next : adj[start]) {
        if (!visited[next]) {
            currStreak++; //reached one more node
            dfs(next);
        }
    }
}

int main() {
    setIO("moocast", true);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> coords[i].first >> coords[i].second >> p[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            float dist = sqrt(pow(coords[i].first-coords[j].first, 2)+pow(coords[i].second-coords[j].second, 2)); //dist formula
            if (dist <= p[i] + 0.000000000001) {
                adj[i].push_back(j); //i cast reaches j
            }
            if (dist <= p[j] + 0.000000000001) {
                adj[j].push_back(i); //j cast reaches i
            } 
        }
    }

    /*for (int i = 0; i < n; i++) {
        cout << "Vertex: " << i << "-->";
        for (int j : adj[i]) {
            cout << j << " ,";
        }
        cout << "\n";
    }*/

    int maxe = 0;
    for (int i = 0; i < n; i++) {
        memset(visited, false, sizeof(visited));
        currStreak=0;
        dfs(i);
        maxe = max(maxe, currStreak);
    }
    cout << maxe+1 << endl;

    return 0;
}