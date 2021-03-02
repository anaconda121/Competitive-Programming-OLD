#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

void setIO(string name = "") { // name is nonempty for USACO file I/O
    ios_base::sync_with_stdio(0); cin.tie(0); // see Fast Input & Output
    // alternatively, cin.tie(0)->sync_with_stdio(0);
    freopen((name+".in").c_str(), "r", stdin); // see Input & Output
    freopen((name+".out").c_str(), "w", stdout);
}

int main(){
    setIO("breedflip");
    int n;
    cin >> n;
    string desired;
    string curr;
    cin >> desired;
    cin >> curr;
    bool mis = false;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (desired[i] != curr[i]) {
            //have a mismatch may need to add to ans
            if (!mis) {
                ans++;
                mis = true;
            }
        } else {
            mis = false;
        }
    }
    cout << ans << endl;
    return 0;
}