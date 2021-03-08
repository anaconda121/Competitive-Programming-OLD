#include <bits/stdc++.h>

using namespace std;

#define maxn 1005 //placeholder value, depends on problem statement
#define pb push_back
vector<int> adj[maxn];
int n;

bool regular(){
    int d = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            d = adj[i].size();
        } else {
            if (adj[i].size() != d) {
                return false;
            }
        }
    }
    return true;
}

bool complete(){
    for (int i = 0; i < n; i++) {
        if (adj[i].size() != n-1) {
            return false;
        }
    }
    return true;
}

int main(){
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a,b;
        cin >> a >> b;
        a--; b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    cout << regular() << endl; // 0 is false, 1 is true
    cout << complete() << endl; // 0 is false, 1 is true
    return 0;
}