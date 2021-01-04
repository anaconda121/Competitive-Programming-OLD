#include <algorithm>
#include <vector>
#include <math.h>
#include <iostream>
#include <stdio.h>

using namespace std;

int n;
vector<int> grades;

void setIO(string name, bool includeout=false) { // name is nonempty for USACO file I/O
    ios_base::sync_with_stdio(0); cin.tie(0); // see Fast Input & Output
    // alternatively, cin.tie(0)->sync_with_stdio(0);
    freopen((name+".in").c_str(), "r", stdin); // see Input & Output
    if (includeout) {
        freopen((name+".out").c_str(), "w", stdout);
    }
}

int main() {
    setIO("homework", true);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        grades.push_back(a);
    }
    
    return 0;
}