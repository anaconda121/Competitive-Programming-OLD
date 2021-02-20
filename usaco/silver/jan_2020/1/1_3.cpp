#include <bits/stdc++.h>

using namespace std;

#define ll = long long;
#define vi = vector<int>;
#define pi = pair<int,int>;
#define sz(x) (int)(x).size()
#define pb push_back
#define all(x) begin(x), end(x)
#define f first
#define s second
#define maxn 1005

int n, k;
int berries[maxn];

void setIO(string name, bool includeout=false) { // name is nonempty for USACO file I/O
    ios_base::sync_with_stdio(0); cin.tie(0); // see Fast Input & Output
    // alternatively, cin.tie(0)->sync_with_stdio(0);
    freopen((name+".in").c_str(), "r", stdin); // see Input & Output
    if (includeout) {
        freopen((name+".out").c_str(), "w", stdout);
    }
}

int main() {
    setIO("berries");
    cin >> n >> k;
    int maxb = 0;
    for (int i = 0; i< n; i++) {
        cin >> berries[i];
        maxb = max(maxb, berries[i]);
    }
    int ans = 0;
    for (int i = 1; i <= maxb; i++) {
        int portions[maxn];
        for (int j = 0; j <= i; j++) {
            portions[j] = 0;
        }
        for (int j = 0; j < n; j++) {  
            portions[i] += berries[j] / i;
            portions[berries[j] % i]++;
        }
        if (k/2 > portions[i]) {
            continue;
        }
        portions[i] -= k/2; //given those berries away to elsie
        int givenPortions = 0;
        int currSize = i;
        int total = 0;
        while (currSize > 0 && givenPortions < k/2) {
            if (portions[currSize] > 0) {
                givenPortions++;
                total += currSize;
                cout << currSize << endl;
                portions[currSize]--;
            } else {
                currSize--; //ran out of optimally sized portions
            }
        }
        if (givenPortions == k/2) {
            ans = max(ans, total);
        }
    }
    cout << ans << endl;
    return 0;
}