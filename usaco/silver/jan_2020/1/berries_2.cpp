#include <bits/stdc++.h>

using namespace std;

#define maxn 1005

int n,k;
vector<int> berries;
int ans[maxn];

void setIO(string name, bool includeout=false) { // name is nonempty for USACO file I/O
    ios_base::sync_with_stdio(0); cin.tie(0); // see Fast Input & Output
    // alternatively, cin.tie(0)->sync_with_stdio(0);
    freopen((name+".in").c_str(), "r", stdin); // see Input & Output
    if (includeout) {
        freopen((name+".out").c_str(), "w", stdout);
    }
}

bool cmp (int a, int b){
    return a > b;
}

int main(){
    setIO("berries", true);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        berries.push_back(a);
    }

    sort(berries.begin(), berries.end(), cmp);

    for (int i = k; i <= berries.size(); i++) {
        berries.erase(berries.begin() + i);
    }
    
    for (int i = (k/2); i < k; i++) {
        ans[0] += berries[i];
    }
    int parts = k - berries.size();
    if (parts == 0) {
        parts = 1;
    }
    int sub = berries[0] / (parts+1);
    for (int i = 0; i < parts; i++) {
        berries[0] -= sub;
        berries.push_back(sub);
    }

    sort(berries.begin(), berries.end(), cmp);
    for (int i = k; i <= berries.size(); i++) {
        berries.erase(berries.begin() + i);
    }
    
    for (int i = (k/2); i < k; i++) {
        ans[1] += berries[i];
    }
    cout << max(ans[0], ans[1]) << endl;
    return 0;
}