//http://www.usaco.org/index.php?page=viewproblem2&cpid=666
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void setIO(string name = "") { // name is nonempty for USACO file I/O
    ios_base::sync_with_stdio(0); cin.tie(0); // see Fast Input & Output
    // alternatively, cin.tie(0)->sync_with_stdio(0);
    freopen((name+".in").c_str(), "r", stdin); // see Input & Output
    freopen((name+".out").c_str(), "w", stdout);
}

int main() {
    //input
    setIO("haybales");
    int N, Q;    
    cin >> N >> Q;
    vector<int> bales(N);
    int loc;
    for (int i = 0; i < N; i++) {
        cin >> bales[i];
    }
    sort(begin(bales), end(bales));
    for (int i = 0; i < Q; i++) {
        int A,B; 
        cin >> A >> B;
        vector<int>::iterator it = upper_bound(begin(bales),end(bales),B);
        cout << upper_bound(begin(bales),end(bales),B)-lower_bound(begin(bales),end(bales),A) << "\n";
        //when upperbound - xxx deals with index nums of values of iterators instead
    }
    return 0;
}