/*
logic

find cows that can be reached without a road
if a cow can't be, add to ans
*/

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define f first
#define s second
#define maxn 105

set<pair<int,int>> fields[maxn][maxn];
int n, k, r;
int xArr[4] = {-1,0,1,0};
int yArr[4] = {0,1,0,-1};
int ans = 0;

void floodfill(bool visited[maxn][maxn], int r, int c){
	if(r < 0 || r >= n || c < 0 || c >= n) return; // if outside grid
	if(visited[r][c]) return; // already visited this square
    visited[r][c] = true;
    for (int i = 0; i < 4; i++) {
        if (!fields[r][c].count({r + xArr[i], c + yArr[i]})) {
            //another point we can visit
            //pair<int,int> currP = make_pair(r + xArr[i], c + yArr[i]);
            //if (find(locations.begin(), locations.end(), currP) != locations.end()) {
            //    ans++;
            floodfill(visited, r + xArr[i], c + yArr[i]);
            //}
        }
    }
}

int main() {
    freopen("countcross.in", "r", stdin);
    freopen("countcross.out", "w", stdout);
    cin >> n >> k >> r;
    for (int i = 0; i < r; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--; y1--; x2--; y2--;
        fields[x1][y1].insert({x2, y2});
        fields[x2][y2].insert({x1, y1});
    }
    vector<pair<int,int>> locations (k);
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        locations[i]={x, y};
        // cout << locations[i].f << endl;
        bool visited[maxn][maxn];
        floodfill(visited, x, y);
        for(int j = 0; j < i; j++){
            int idx1 = locations[j].first;
            int idx2 = locations[j].second;
            if (!visited[idx1][idx2]){
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
