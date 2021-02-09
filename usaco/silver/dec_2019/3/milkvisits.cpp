#include <bits/stdc++.h>

using namespace std;

#define maxn 100005

int n, m;
int v = 0;
string pref;
string ans = "";
vector<pair<int, char>> adj[maxn];
bool visited[maxn];
int pred[maxn], dist[maxn];
bool got = false;


void setIO(string name, bool includeout=false) { // name is nonempty for USACO file I/O
    ios_base::sync_with_stdio(0); cin.tie(0); // see Fast Input & Output
    // alternatively, cin.tie(0)->sync_with_stdio(0);
    freopen((name+".in").c_str(), "r", stdin); // see Input & Output
    if (includeout) {
        freopen((name+".out").c_str(), "w", stdout);
    }
}

bool BFS(int src, int dest, char preference){
    // a queue to maintain queue of vertices whose
    // adjacency list is to be scanned as per normal
    // DFS algorithm
    list<int> queue;
 
    // boolean array visited[] which stores the
    // information whether ith vertex is reached
    // at least once in the Breadth first search
 
    // initially all vertices are unvisited
    // so v[i] for all i is false
    // and as no path is yet constructed
    // dist[i] for all i set to infinity
    for (int i = 0; i < v; i++) {
        visited[i] = false;
        dist[i] = INT_MAX;
        pred[i] = -1;
    }
 
    // now source is first to be visited and
    // distance from source to itself should be 0
    visited[src] = true;
    dist[src] = 0;
    queue.push_back(src);
 
    // standard BFS algorithm
    while (!queue.empty()) {
        int u = queue.front();
        queue.pop_front();
        for (int i = 0; i < adj[u].size(); i++) {
            if (visited[adj[u][i].first] == false) {
                visited[adj[u][i].first] = true;
                dist[adj[u][i].first] = dist[u] + 1;
                pred[adj[u][i].first] = u;
                queue.push_back(adj[u][i].first);
 
                // We stop BFS when we find
                // destination.
                if (adj[u][i].second == preference)
                    cout << adj[u][i].first << " " << adj[u][i].second << " " << preference << endl;
                    return true;
                if (adj[u][i].first == dest) 
                    break;
            }
        }
    }
 
    return false;
}

void printShortestDistance(int s,
                           int dest, char pref)
{
    // predecessor[i] array stores predecessor of
    // i and distance array stores distance of i
    // from s
 
    if (BFS(s, dest, pref) == false) {
        cout << "Given source and destination"
             << " are not connected";
        return;
    }
 
    // vector path stores the shortest path
    vector<int> path;
    int crawl = dest;
    path.push_back(crawl);
    while (pred[crawl] != -1) {
        path.push_back(pred[crawl]);
        crawl = pred[crawl];
    }
 
    // distance from source is in distance array
    cout << "Shortest path length is : "
         << dist[dest] + 1;
 
    // printing path from source to destination
    cout << "\nPath is::\n";
    for (int i = path.size() - 1; i >= 0; i--)
        cout << path[i] << " ";
}
 

int main() {
    setIO("milkvists");
    cin >> n >> m;
    cin >> pref;
    v = n;
    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b; 
        a--; b--;
        adj[a].push_back(make_pair(b, pref[b]));
        adj[b].push_back(make_pair(a, pref[a]));
        //cout << a << " " << pref[i] << endl;
        //cout << b << " " << pref[i] << endl;
        /*for (auto element : adj[a]) {
            cout << element.first << " , " << element.second << endl;
        }*/
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        char c;
        cin >> a >> b >> c;
        bool happy = BFS(a, b, c);
        if (happy) ans += '1';
        else ans += '0';
        happy = false;
        got = false;
        //printShortestDistance(a,b,c);
    }
    cout << ans << endl;

    return 0;
}