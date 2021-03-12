/*LOGIC
http://www.usaco.org/index.php?page=viewproblem2&cpid=570

logic is in comments all around code
*/

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define f first
#define s second
#define maxn 105

int n,m;
int xArr[4] = {0,0,-1,1};
int yArr[4] = {1,-1,0,0};
bool lit[maxn][maxn];
bool visited[maxn][maxn];
long long area = 0;
long long ans = 1;
vector<vector<vector<pair<int,int>>>> lights (maxn, vector<vector<pair<int, int>>>(maxn, vector<pair<int, int>>()));

void setIO(string name, bool includeout=false) { // name is nonempty for USACO file I/O
    ios_base::sync_with_stdio(0); cin.tie(0); // see Fast Input & Output
    // alternatively, cin.tie(0)->sync_with_stdio(0);
    freopen((name+".in").c_str(), "r", stdin); // see Input & Output
    if (includeout) {
        freopen((name+".out").c_str(), "w", stdout);
    }
}

void floodfill(int r, int c){
	if(r < 0 || r >= n || c < 0 || c >= n) return; // if outside grid
	if(visited[r][c]) return; // already visited this square
    if(!lit[r][c]) return; //bessie can only travel through lit rooms
	visited[r][c] = true; // mark current square as visited
    for (auto x : lights[r][c]) {
        if (!lit[x.f][x.s]) {
            lit[x.f][x.s] = true;
            ans++;
            for (int i = 0; i < 4; i++) {
                //range check
                if (x.f + xArr[i] >= n || x.f + xArr[i] < 0) continue;
				if (x.s + yArr[i] >= n || x.s + yArr[i] < 0) continue;
                // if dood is visited, that must mean could be some more light switches that need to be toggled
                // so go over there and check it out
                // have to use visited here instead of lit since dood who can toggle lit switches but isn't toggled by anyone
                // will only have visited = true and not lit. this is bad because dood could have ability to toggle multiple
                // which isnt getting leveraged.
                int row = x.f + xArr[i];
                int col = x.s + yArr[i];
                if (visited[row][col]) {
                    floodfill(x.f, x.s);
                }
            }
        }
    }
	//recursively call floodfill for neighboring squares
	for (int i = 0; i < 4; i++) {
        floodfill(r + xArr[i], c + yArr[i]);
    }
}

int main() {
    setIO("lightson", true);
    cin >> n >> m;
    lit[0][0] = true;
    for (int i = 0; i < m; i++) {
        int x,y, x2, y2;
        cin >> x >> y >> x2 >> y2;
        x--; y--; x2--; y2--; 
        lights[x][y].push_back({x2,y2});
    }
    // for (auto i : lights) {
    //     for (auto j : i) {
    //          for (auto k : j) {
    //                cout << k.first << " " << k.second << " , "; 
    //            }
    //          cout << endl;
    //     }
    // }
    floodfill(0,0);
    cout << ans << endl;
    return 0;
}