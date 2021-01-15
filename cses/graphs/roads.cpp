//https://cses.fi/problemset/task/1666/

#include <algorithm>
#include <vector>
#include <math.h>
#include <iostream>

using namespace std;

int cities, roads;
vector<int> adj[100002]; //adjacency list
bool visited[100002];
int rep[100002];

void dfs(int start) {
    if (visited[start] == true) return;
    visited[start] = true;
    for (auto next : adj[start]) {
        if (!visited[next]) {
            dfs(next);
        }
    }
}

int countComponents(){
    int count = 0;
    for (int i = 1; i <= cities; i++) {
        if (!visited[i]){
            dfs(i);
            rep[count++]=i; //gets first node in each connected component
        }
    }
    return count;
}

/*LOGIC
find number of connected components in graph, number of roads needed is that -1
then u can choose any element from a corresponding pair of adj_lists
*/

int main() {
    cin >> cities >> roads;
    for (int i = 0; i < roads; i++) {
        int a, b;
        cin >> a >> b;
        //creating adj_list
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int ans = countComponents();
    cout << ans-1 << endl;
    for (int i = 1; i < ans; i++){
        cout << rep[i-1] << " " << rep[i] << endl;
    }
    return 0;
}