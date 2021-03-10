/*LOGIC

boolean matrix 
*/

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define f first
#define s second
#define maxn 105

int n,m;
bool grid[maxn][maxn];
bool visited[maxn][maxn];
long long area = 0;
long long ans = INT_MIN;


void setIO(string name, bool includeout=false) { // name is nonempty for USACO file I/O
    ios_base::sync_with_stdio(0); cin.tie(0); // see Fast Input & Output
    // alternatively, cin.tie(0)->sync_with_stdio(0);
    freopen((name+".in").c_str(), "r", stdin); // see Input & Output
    if (includeout) {
        freopen((name+".out").c_str(), "w", stdout);
    }
}

void floodfill(vector<vector<vector<pair<int,int>>>> lights, int r, int c){
	if(r < 0 || r >= n || c < 0 || c >= n) return; // if outside grid
	if(visited[r][c]) return; // already visited this square
    if(!grid[r][c]) return; //not true, can't move from here to anywhere else
	visited[r][c] = true; // mark current square as visited
    for (auto x : lights[r][c]) {
        
    }
	//recursively call floodfill for neighboring squares
	floodfill(lights, r, c+1);
	floodfill(lights, r, c-1);
	floodfill(lights, r-1, c);
	floodfill(lights, r+1, c);
}

int main() {
    setIO("lightson");
    cin >> n >> m;
    vector<vector<vector<pair<int,int>>>> lights (n, vector<vector<pair<int, int>>>(n, vector<pair<int, int>>()));
    for (int i = 0; i < m; i++) {
        int x,y, x2, y2;
        cin >> x >> y >> x2 >> y2;
        x--; y--; x2--; y2--; 
        lights[x][y].push_back({x2,y2});
        grid[x][y] = grid[x2][y2] = true;
    }
    // for (auto i : lights) {
    //     for (auto j : i) {
    //          for (auto k : j) {
    //                cout << k.first << " " << k.second << " , "; 
    //            }
    //          cout << endl;
    //     }
    // }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (grid[i][j] && !visited[i][j]) {
                floodfill(lights,i,j);
                ans = max(ans, area);
                area = 0;
                cout << ans << endl;
            }
        }
    }
    return 0;
}
