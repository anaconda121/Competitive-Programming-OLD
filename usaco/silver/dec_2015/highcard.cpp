#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void setIO(string name = "") { // name is nonempty for USACO file I/O
    ios_base::sync_with_stdio(0); cin.tie(0); // see Fast Input & Output
    // alternatively, cin.tie(0)->sync_with_stdio(0);
    freopen((name+".in").c_str(), "r", stdin); // see Input & Output
    freopen((name+".out").c_str(), "w", stdout);
}

int main() {
    setIO("highcard");
    int n;
    cin >> n;
    vector<bool> elsie (2*n+1);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        elsie[a] = true;
    }
    vector<int> e;
    vector<int> b;
    int j = 0;
    for (int i = 1; i < 2*n+1; i++) {
        if(elsie[i]) {
            e.push_back(i);
        } else {
            b.push_back(i);
        }
    }
    int count = 0;
    int e_idx = 0;
    int b_idx = 0;
    sort(begin(e),end(e));
    sort(begin(b),end(b));
    //for (auto element : e) {
    //    cout << element << " , ";
    //}
    //cout << "\n";
    //for (auto element : b) {
    //    cout << element << " , ";
    //}
    //cout << "\n";

    while (e_idx <= n && b_idx <= n) {
        //cout << b_idx << " , " << b[b_idx] << " --- " << e_idx << " , "  << e[e_idx] << endl; 
        if (b[b_idx] > e[e_idx]) {
            count++;
            b_idx++;
            e_idx++;
        } else {
            b_idx++;
        }
    }
    cout << count << endl;
    //for (auto element : cows) {
    //    cout << element.first << " , " << element.second << endl;
    //}
    return 0;
}