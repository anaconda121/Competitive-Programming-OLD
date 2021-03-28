#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define f first
#define s second
#define maxn 105

int n, k, r;
bool visited[maxn][maxn];
int roads[maxn][maxn];
vector<pair<int,int>> locations (maxn);
pair<int,int> startPos;
int roadCount = 0;
int ans = 0;
int xArr[4] = {0,0,-1,1};
int yArr[4] = {1,-1,0,0};

void setIO(string name = "", bool includeout = false) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((name+".in").c_str(), "r", stdin);
    if (includeout)
        freopen((name+".out").c_str(), "w", stdout);
}

void floodfill(int r, int c, int rD, int cD){
	if(r < 0 || r > 100 || c < 0 || c > 100) return; // if outside grid
	if(visited[r][c]) return; // already visited this square
	visited[r][c] = true; // mark current square as visited
    if (roads[r][c] == 1) {
        //traveling along a road
        roadCount++;
    }
    if (r == rD && c == cD) {
        return;
    }
    for (int i = 0; i < 4; i++) {
        floodfill(r + xArr[i], c + yArr[i], rD, cD);
    }
}

int main() {
    setIO("countcross", true);
    cin >> n >> k >> r;
    for (int i = 0; i < r; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        roads[x1][y1] = roads[x2][y2] = 1;
    }
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        locations[i] = {x, y};
        if (i == 0) {
            startPos = {x, y};
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n; j++) {
            floodfill(locations[i].f, locations[i].s, locations[j].f, locations[j].s);
            if (roadCount > 0) {
                ans++;
                //cout << locations[i].f << " , " << locations[i].s << endl;
                //cout << locations[j].f << " , " << locations[j].s << endl;
            }
            roadCount = 0;
        }
    }
    cout << n-ans << endl;
    return 0;
}
