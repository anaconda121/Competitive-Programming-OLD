#include <algorithm>
#include <vector>
#include <math.h>
#include <iostream>
#include <stdio.h>

using namespace std;

int cows, queries;

void setIO(string name, bool includeout=false) { // name is nonempty for USACO file I/O
    ios_base::sync_with_stdio(0); cin.tie(0); // see Fast Input & Output
    // alternatively, cin.tie(0)->sync_with_stdio(0);
    freopen((name+".in").c_str(), "r", stdin); // see Input & Output
    if (includeout) {
        freopen((name+".out").c_str(), "w", stdout);
    }
}

/* LOGIC
    1.to find cows from iterval [a,b], use partial sums
    2.find count of each type from cow from interval [1,b] and [1,a-1]. subtract count from [1,b] from [1,a-1]
    3.to create prefix sum, have the value at the next index inherit the previous value. if the id from the cow 
    taken falls into a certain array (h for id1, g for id2, j for id3), then have the value at the i+1 index++
    4. print out answer using partial sums formula
*/

int main() {
    setIO("bcount",true);
    int n, q;
    cin >> n >> q;
    int h[n + 1], g[n + 1], j[n + 1];

    for (int i = 0; i < n; i++) {
        h[i + 1] = h[i];
        g[i + 1] = g[i];
        j[i + 1] = j[i];
        int id;
        cin >> id;

        if (id == 1) h[i + 1]++;
        else if (id == 2) g[i + 1]++;
        else j[i + 1]++;

    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << h[r] - h[l - 1] << ' ' << g[r] - g[l - 1] << ' ' << j[r] - j[l - 1] << '\n';
    }
    return 0;
}