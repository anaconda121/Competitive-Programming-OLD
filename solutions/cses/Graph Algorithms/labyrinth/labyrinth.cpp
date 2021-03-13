// come back and use BFS!!!!!!!!!!!!!!

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define f first
#define s second
#define MAXN 1005
#define MAXM 1005

int n, m;
char grid[MAXN][MAXM];
bool visited[MAXN][MAXM]; // keeps track of which nodes have been visited
ll ans = 0; // reset to 0 each time we start a new component
ll curr = 0;
pair<int,int> aPos;
string path = "";
string currPath = "";

void setIO(string name, bool includeout=false) { // name is nonempty for USACO file I/O
    ios_base::sync_with_stdio(0); cin.tie(0); // see Fast Input & Output
    // alternatively, cin.tie(0)->sync_with_stdio(0);
    freopen((name+".in").c_str(), "r", stdin); // see Input & Output
    if (includeout) {
        freopen((name+".out").c_str(), "w", stdout);
    }
}

void floodfill(int r, int c, string dir){
	if(r < 0 || r >= n || c < 0 || c >= m) {
        //cout << "out of bounds " << grid[r][c] << " " << r << " " << c << endl;
        return;
    } 
	if(grid[r][c] == '#') {
        //cout << "hashtag " << grid[r][c] << " " << r << " " << c << endl;
        return; 
    }
    if(visited[r][c]) return;
	visited[r][c] = true; 

	currPath += dir;  
    if (grid[r][c] == 'B') {
        if (path.size() == 0 || currPath.size() < path.size()){
            path = currPath;
            //cout << "found path " << path << " test " << r << " " << c << endl;
        } 
        currPath = "";
        return;
    }
	 
	//cout << currPath << " " << grid[r][c] << " " << r << " " << c << endl;

	floodfill(r, c+1, "R");
	floodfill(r, c-1, "L");
	floodfill(r-1, c, "U");
	floodfill(r+1, c, "D");
}

int main() {
    setIO("labryinth");
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char a;
            cin >> a;
            grid[i][j] = a;
            if (a == 'A') {
                aPos = {i, j};
            }
        }
    }
    floodfill(aPos.f, aPos.s, "");
    if (path.size() != 0) {
        cout << "YES" << endl;
        cout << path.size() << endl;
        cout << path << endl;
    } else {
        cout << "NO" << endl; 
    }
    return 0;
}
