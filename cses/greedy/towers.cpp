#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> towers;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (towers.size() == 0) {
            towers.push_back(a);
        } else {
            /*for (int j = 0; j < towers.size(); j++) {
                if (a < towers[j]) {
                    towers[j] = a;
                    add = false;
                    break;
                }
            }*/
            auto it = upper_bound(begin(towers), end(towers), a);
            if (it - begin(towers) == towers.size()) {
                towers.push_back(a);
            } else {
                towers[it-begin(towers)] = a;
            }
            //cout << *it << endl;
        }
    }
    cout << towers.size() << endl;
    return 0;
}