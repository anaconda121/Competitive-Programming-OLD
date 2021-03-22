#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define f first
#define s second
#define maxn 105

int n, k, r;
int grid[maxn][maxn]; // the grid itself
bool visited[maxn][maxn]; // keeps track of which nodes have been visited
vector<tuple<int,int,int,int>> roads;
vector<pair<int,int>> locations;
ll ans = 0;

void setIO(string name, bool includeout=false) { // name is nonempty for USACO file I/O
    ios_base::sync_with_stdio(0); cin.tie(0); // see Fast Input & Output
    // alternatively, cin.tie(0)->sync_with_stdio(0);
    freopen((name+".in").c_str(), "r", stdin); // see Input & Output
    if (includeout) {
        freopen((name+".out").c_str(), "w", stdout);
    }
}

void floodfill(int r, int c){
	if(r < 0 || r > 100 || c < 0 || c > 100) return; // if outside grid
	if(visited[r][c]) return; // already visited this square
	visited[r][c] = true; // mark current square as visited
    ll idx = 0;
    for (auto road : roads) {
        if (get<0>(road) == r && get<1>(road) == c) {
            int end1 = get<2>(road);
            int end2 = get<3>(road);
            if (grid[end1][end2] == 1) {
                cout << "road that needs to be deleted " << get<0>(road) << " , " << get<1>(road) << " , "  << get<2>(road) << " , " << get<3>(road) << endl; 
                ans++;
                cout << idx << endl;
                if (idx == 0) {
                    roads.erase(roads.begin());
                } else if (idx != 0) {
                    roads.erase(roads.begin(), roads.begin() + idx);
                }
            }
        }
        idx++;
        cout << "\n";
        for (auto x : roads) {
            cout << "remaining roads " << get<0>(x) << " , " << get<1>(x) << " , "  << get<2>(x) << " , " << get<3>(x) << endl; 
        }
    }
}

int main() {
    setIO("countcross");
    cin >> n >> k >> r;
    for (int i = 0; i < r; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        roads.pb(make_tuple(a, b, c, d));
    }
    // for (auto x : roads) {
    //     cout << get<0>(x) << " , " << get<1>(x) << " , "  << get<2>(x) << " , "  << get<3>(x) << endl; 
    // }
    ll currsize = roads.size();
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        grid[a][b] = 1;
        locations.pb(make_pair(a, b));
    }
    // for (auto y : locations) {
    //     cout << y.f << y.s << endl; 
    // }
    for (auto loc : locations) {
        //cout << loc.f << loc.s << endl;
        floodfill(loc.f, loc.s);
    }
    //cout << roads.size() << endl;
    // cout << grid[3][3] << endl;
    // cout << grid[2][3] << endl;
    cout << ans << endl;
    return 0;
}
