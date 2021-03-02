#include <algorithm>
#include <vector>
#include <math.h>
#include <iostream>
#include <stdio.h>
#include <climits>

using namespace std;

int n, k;
int grid[1002][1002];

void setIO(string name, bool includeout=false) { // name is nonempty for USACO file I/O
    ios_base::sync_with_stdio(0); cin.tie(0); // see Fast Input & Output
    // alternatively, cin.tie(0)->sync_with_stdio(0);
    freopen((name+".in").c_str(), "r", stdin); // see Input & Output
    if (includeout) {
        freopen((name+".out").c_str(), "w", stdout);
    }
}

int main() {
    setIO("paintbarn", true);
    cin >> n >> k;
    int minx, miny = INT_MAX;
    int maxx, maxy = INT_MIN;
    for (int i = 0; i < n; i++) {
        int x,y,x2,y2;
        cin >> x >> y >> x2 >> y2;
        for (int j = x; j < x2; j++) {
            for (int k = y; k < y2; k++) {
                grid[j][k]++;
            }
        }
        minx = min(minx, min(x, x2));
        maxx = max(maxx, max(x,x2));
        miny = min(miny, min(y,y2));
        maxy = max(maxy, max(y,y2));
    }
    //cout << minx << " " << maxx << " " << miny << " " << maxy << endl; 
    int count = 0;
    for (int i = minx; i < maxx; i++) {
        for (int j = miny; j < maxy; j++) {
            if (grid[i][j] == k) {
                count++;
            }
        }
    }
    cout << count << endl;
    return 0;
}