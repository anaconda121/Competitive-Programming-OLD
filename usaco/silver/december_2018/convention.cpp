#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

using ll = long long;
using namespace std;

void setIO(string name = "") { // name is nonempty for USACO file I/O
    ios_base::sync_with_stdio(0); cin.tie(0); // see Fast Input & Output
    // alternatively, cin.tie(0)->sync_with_stdio(0);
    freopen((name+".in").c_str(), "r", stdin); // see Input & Output
    freopen((name+".out").c_str(), "w", stdout);
}

int main(){
    setIO("convention");
    int n,m,c;
    cin >> n >> m >> c;
    vector<int> t (n);
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }

    /*for (int i = 0; i < t.size(); i++) { 
        for (int j = 0; j < t[i].size(); j++) 
            cout << t[i][j] << " "; 
        cout << endl; 
    } */

    sort(begin(t),end(t));
    vector<int> v;
    int count = 0;
    int diff = 0;
    int bus = 0;
    for (int i = 0; i < n; i++) {
        if (count < c) {
            v.push_back(t[i]);
            count++;
        } else if (count == c) {
            bus++;
			int d = *max_element(begin(v),end(v)) - *min_element(begin(v),end(v));
            diff = max(d, diff);
            //cout << diff << " , " << d << endl; 
            if (i < n) {
                count = 1;
                v.clear();
                v.push_back(t[i]);
            }
        }
        if (count == c && bus < m) {
            int d = *max_element(begin(v),end(v)) - *min_element(begin(v),end(v));
            diff = max(d, diff);
        }
        /*for (auto element : v) {
            cout << element <<"  , "; 
        }
        cout << "\n";*/
    }
	cout << diff << endl;

    return 0;
}