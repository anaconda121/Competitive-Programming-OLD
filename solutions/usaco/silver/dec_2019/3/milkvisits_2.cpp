#include <bits/stdc++.h>

using namespace std;

#define maxn 100005

int n, m, cc; // cc = componentCount
int components[maxn]; //stores what component each farm is part of
string s; //holds cow breed preferences for each farmer
char pref[maxn]; //char array based of s since we are using 1-index system
vector<int> adj[maxn]; //adjacency list for representing graph

//input function
void setIO(string name, bool includeout=false) { 
    ios_base::sync_with_stdio(0); cin.tie(0); 
    freopen((name+".in").c_str(), "r", stdin); 
    if (includeout) {
        freopen((name+".out").c_str(), "w", stdout);
    }
}

void dfs(int start) {
    if (components[start] != 0) {
		//current farm has already been assigned a component b/c it has already been visited
        return;
    }
    components[start] = cc; //assign component # to farm
    for (auto next : adj[start]) {
        if (pref[start] == pref[next]) {
			//found another farm to add to our current component
            dfs(next);
        }
    }
}

int main() {
    setIO("milkvisits", true);
    string ans = "";
    cin >> n >> m;
    cin >> s;
    for (int i = 1; i < n+1; i++) {
        pref[i] = s[i-1];
    }
	//creating graph
    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
	//creating connected components
    for (int i = 1; i < n+1; i++) {
		if (components[i] == 0) {
			//add new component
			cc++;
			dfs(i);
    	}
	}
    for (int i = 0; i < m; i++) {
        int a, b;
        char c;
        cin >> a >> b >> c;
        if ((components[a] == components[b] && pref[a] == c) || components[a] != components[b]) {
            ans += '1';
        } else {
            ans += '0';
        }
    }
    cout << ans << endl;
    return 0;
}