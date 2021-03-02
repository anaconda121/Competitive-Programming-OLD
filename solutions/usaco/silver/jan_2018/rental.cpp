#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <climits>

using namespace std;

void setIO(string name = "") { // name is nonempty for USACO file I/O
    ios_base::sync_with_stdio(0); cin.tie(0); // see Fast Input & Output
    // alternatively, cin.tie(0)->sync_with_stdio(0);
    freopen((name+".in").c_str(), "r", stdin); // see Input & Output
    freopen((name+".out").c_str(), "w", stdout);
}

bool cmp (int a, int b) {
    return a > b;
}

bool cmp2 (pair<int,int>p, pair<int,int>p2) {
    return p.second < p2.second;
}

int main() {
    setIO("rental");
    int n, m, r;
    cin >> n >> m >> r;
    vector<int> gals(n);
    vector<pair<int,int>> shops(m);
    vector<int> rent(r);
    for (int i = 0; i < n; i++) {
        cin >> gals[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> shops[i].first >> shops[i].second;
        //shops[i].second *= shops[i].first;
    }
    for (int i = 0; i < r; i++) {
        cin >> rent[i];
    }
    // sort gals from least - greatest
    // sort shops from least - greatest
    // sort rentals from greatest to least
    sort(begin(gals), end(gals));
    sort(begin(shops), end(shops), cmp2);
    sort(begin(rent), end(rent), cmp);

    gals.resize(n);
    shops.resize(n);
    rent.resize(n);
    sort(begin(shops), end(shops), cmp2);

    int storeIndex = m-1;
    int cowIndex = n-1;
    while(storeIndex >= 0 && cowIndex >= 0) {
        if (gals[cowIndex] < shops[cowIndex].first) {
            shops[cowIndex].second += (long) gals[cowIndex] * shops[storeIndex].second;
            shops[storeIndex].first -= gals[cowIndex];
            //gals[cowIndex] = 0;
            cowIndex--; //on to next cow
        } else if (gals[cowIndex] > shops[cowIndex].first) {
            shops[cowIndex].second += (long) shops[storeIndex].first * shops[storeIndex].second; //take everything
            gals[cowIndex] -= shops[storeIndex].first;
            storeIndex--; //on to next store
        } else if (gals[cowIndex] == shops[cowIndex].first){
            shops[cowIndex].second += (long)gals[cowIndex] * shops[storeIndex].second;
            gals[cowIndex] = 0;
            shops[storeIndex].first = 0;
            cowIndex--; //finished both curr cow and curr store
            storeIndex--;
        }
    }

    for (auto element:gals) {
        cout << element << endl;
    }
    cout << "\n";
    for (auto element:shops) {
        cout << element.first << " " << element.second << endl;
    }
    cout << "\n";
    for (auto element : rent) {
        cout << element << endl;
    }
    return 0;
}