#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vi vector<int>
#define pi pair<int,int>
#define pb push_back
#define f first
#define s second

int n, k;
set<int> tree;

void setIO(string name, bool includeout=false) { // name is nonempty for USACO file I/O
    ios_base::sync_with_stdio(0); cin.tie(0); // see Fast Input & Output
    // alternatively, cin.tie(0)->sync_with_stdio(0);
    freopen((name+".in").c_str(), "r", stdin); // see Input & Output
    if (includeout) {
        freopen((name+".out").c_str(), "w", stdout);
    }
}

int main() {
    //setIO("2", true);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        tree.insert((12+a)/12);
    }
    vector<int> ancestors;
    ancestors.assign(tree.begin(), tree.end());
    sort(ancestors.begin(), ancestors.end());

    int diff[tree.size()];
    int prev = 0;
    for (int i = 0; i < tree.size(); i++) {
        diff[i] = ancestors[i] - prev - 1;
        prev = ancestors[i];
    }
    int n = sizeof(diff) / sizeof(diff[0]);
    sort(diff, diff + n); 
    int l = n;
    int jY = 0;
    for (int i = 0; i < k-1; i++) {
        jY += 12 * diff[l - i - 1];
    }
    int yT = 12 * ancestors[ancestors.size()-1]- jY;
    cout << yT << endl;
    return 0;
}