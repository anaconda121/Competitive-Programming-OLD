#include <iostream>
#include <algorithm>
#include <math.h>
#include <set>

using namespace std;

int numCities, numTowers;
set<int> cities;
set<int> towers;

int main(){
    cin >> numCities >> numTowers;
    for (int i = 0; i < numCities; i++) {
        int a;
        cin >> a;
        cities.insert(a);
    }
    for (int i = 0; i < numTowers; i++) {
        int a;
        cin >> a;
        towers.insert(a);
    }

    long long dist=0;
    long long ans=0;
    int count = 0;
    for (int i = 0; i < numTowers; i++) {
        auto it = towers.begin();
        advance(it,i);
        long long curr = *it;
        auto it2 = cities.upper_bound(curr);
        if (it2 != cities.begin()) {
            it2--;
        }
        if (i == numTowers -1 && it2 != cities.end()) {
            dist = abs(curr - *cities.rbegin());
            //cout << "end: " << *cities.rbegin() << endl << flush;
        } else {
            dist = abs(curr - *it2); 
        }
        cout <<dist << " , " << curr << " , " << *it2 << endl << flush;
        ans = max (ans,dist);
        dist = 0;
    }
    cout << ans << endl << flush;
    //cout << search()  << endl << flush;
    return 0;
}