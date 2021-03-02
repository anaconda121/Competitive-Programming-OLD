#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

/*void setIO(string name = "") { // name is nonempty for USACO file I/O
    ios_base::sync_with_stdio(0); cin.tie(0); // see Fast Input & Output
    // alternatively, cin.tie(0)->sync_with_stdio(0);
    freopen((name+".in").c_str(), "r", stdin); // see Input & Output
    freopen((name+".out").c_str(), "w", stdout);
}*/


void ans(vector<int> actual, vector<int> desired, int diff) {
    sort(begin(actual), end(actual));
    sort(begin(desired), end(desired));
    int match = 0;
    for (unsigned int i = 0; i < desired.size(); i++) {
        auto it = lower_bound(begin(actual), end(actual), desired[i]);
        //auto it2 = lower_bound(begin(actual), end(actual), desired[i]+diff);
        //auto it3 = lower_bound(begin(actual), end(actual), desired[i]-diff);
        if (*it == (desired[i]) || (*it <= (desired[i]+diff) && *it >= (desired[i]-diff))) {
            match++;
            cout << "match it -- " << i << " , " << *it << endl;
            int idx = it-actual.begin();
            cout << "index: " << idx << endl;
            actual.erase(remove(actual.begin(), actual.end(), *it));
        } 
        for (auto element : actual) {
            cout << element << " , "; 
        }
        cout << "\n";
        if (actual.size() == 0) {
            break;
        }
        cout << "actual size: " << actual.size() << " , " << i << endl;
        cout << "count: " << match << endl;

    }
}

void ans2(vector<int> actual, vector<int> desired, int diff) {
    sort(begin(actual), end(actual));
    sort(begin(desired), end(desired));
    int i = 0;
    int j = 0;
    int count = 0;
    while (i < desired.size() && j < actual.size()) {
        if (desired[i]+diff < actual[j]) {
            i++;
        } else if (desired[i]-diff > actual[j]) {
            j++;
        } else {
            i++;
            j++;
            count++;
        }
    }
    cout << count << endl;
}

int main(){
    //setIO("apartments");
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a;
    vector<int> b;
    for (int i = 0; i < n; i++) {
        int z;
        cin >> z;
        a.push_back(z);
    }
    for (int i = 0; i < x; i++) {
        int y;
        cin >> y;
        b.push_back(y);
    } 
    ans2(b,a,y);
}
