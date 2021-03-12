template<typename T>
class Graph {
    map<T, list<T>> adjList;
 
public:
    Graph() {
 
    }
    map<T, bool> vis;
    void addEdge(T u, T v, bool bidir = true) {
        adjList[u].push_back(v);
        if (bidir) {
            adjList[v].push_back(u);
        }
    }
 
    void Print() {
        // iterate over the map
        for (auto par : adjList) {
            cout << par.first << "-> ";
            for (auto child : par.second) {
                cout << child << ", ";
            }
            cout << endl;
        }
    }
 
    void bfs(T src) {
        queue<int> q;
        q.push(src);
        while (!q.empty()) {
            T par = q.front();
            q.pop();
            db1(par);
            vis[par] = true;
            for (auto child : adjList[par]) {
                if (!vis[child]) {
                    q.push(child);
                    vis[child] = true;
                }
            }
        }
    }
    void dfs(T src) {
        if (vis[src]) {
            print(src);
            return;
        }
        vis[src] = true;
        for (auto child : adjList[src]) {
            // cout << src << ' ' << child << endl;
            dfs(child);
        }
    }
};