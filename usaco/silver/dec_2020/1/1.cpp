#include <bits/stdc++.h>

using namespace std;

#define maxn 100005
int n;
vector<int> adj[maxn];
bool visited[maxn];

void setIO(string name, bool includeout=false) { // name is nonempty for USACO file I/O
    ios_base::sync_with_stdio(0); cin.tie(0); // see Fast Input & Output
    // alternatively, cin.tie(0)->sync_with_stdio(0);
    freopen((name+".in").c_str(), "r", stdin); // see Input & Output
    if (includeout) {
        freopen((name+".out").c_str(), "w", stdout);
    }
}

int dfs(int start, int parent) {
	int ans = 0;
    
	int cows = adj[start].size();
    if (parent == -1) { 
		cows++;
	}

    int currCows = 1;
    int days = 0;
    while (currCows < cows) {
        days++;
        currCows *= 2;
    }

    ans += days;

    for (auto next : adj[start]) {
        if (next != parent) {
            ans += dfs(next, start) + 1;
        }
    }
	return ans;
}

int main() {
    //setIO("1");
	cin >> n;
	for (int i = 0; i < n-1;i++) {
		int a,b;
		cin >> a >> b;
		//a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	cout << dfs(1,-1) << endl;
    return 0;
}