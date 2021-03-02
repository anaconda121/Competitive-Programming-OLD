//http://www.usaco.org/index.php?page=viewproblem2&cpid=1062

/*LOGIC
  1
 / \
 2  3
/    \ 
4     5
      /
	  6

We start at root node. 

Need to make enough cows so that they can spead to parent of curr_node, and then we will go to each parent and repeat that process until the whole farm is infected.

Instead of visited arr, we can keep track of parent for curr_node and make sure next node we visit is not the parent node. 

*/

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
		//adjacency_list of root node + 1 = total # of cows that need to be there when cloning is finished
		cows++;
	}

    int currCows = 1;
    int days = 0;

	//cloning cows and seeing how many days it will take
    while (currCows < cows) {
        days++;
        currCows *= 2;
    }

    ans += days;

    for (auto next : adj[start]) {
        if (next != parent) {
            ans += dfs(next, start) + 1; //doing +1 because takes 1 day for the sick cow to travel to next node, so need to factor that in to ans
        }
    }
	return ans;
}

int main() {
    setIO("1");
	cin >> n;
	for (int i = 0; i < n-1;i++) {
		int a,b;
		cin >> a >> b;
		a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	cout << dfs(0,-1) << endl;
    return 0;
}