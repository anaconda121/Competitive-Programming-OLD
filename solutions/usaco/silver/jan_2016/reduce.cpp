#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

void setIO(string name = "") { // name is nonempty for USACO file I/O
    ios_base::sync_with_stdio(0); cin.tie(0); // see Fast Input & Output
    // alternatively, cin.tie(0)->sync_with_stdio(0);
    freopen((name+".in").c_str(), "r", stdin); // see Input & Output
    freopen((name+".out").c_str(), "w", stdout);
}

struct Cow {
    int x;
    int y;
    float dist;
};

float calcDist(Cow a, Cow b) {
    float dist = sqrt(pow(abs(a.x-b.x), 2) + pow(abs(a.y-b.y), 2));
    return dist;
}

bool cmp (Cow a, Cow b, Cow c) {    
    float d1 = calcDist(a,b);
    float d2 = calcDist(a,c);
    return d1 < d2;
}



int main() {
    setIO("reduce");
    int n;
    cin >> n;
    vector<Cow> c (n);
    for (int i = 0; i < n; i++) {
        cin >> c[i].x >> c[i].y;
        c[i].dist = 0;
    }
    sort(c.begin(), c.end(), cmp);

    for (int i = 0; i < n; i++) {
        if (i < n - 1) {
            c[i].dist = calcDist(c[i], c[i+1]);
        }
    }
    for (auto element : c) {
        cout << element.x << " " << element.y << " " << element.dist << endl;
    }
    return 0;
}