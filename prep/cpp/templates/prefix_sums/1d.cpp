#include <algorithm>
#include <vector>
#include <math.h>
#include <iostream>
#include <stdio.h>

using namespace std;
using ll = long long;
using vl = vector<ll>;

vl psum(vl a) {
    vl psum(a.size()); 
    for (int i = 0; i < a.size(); ++i)
        if (i > 0)
            psum[i] = psum[i-1]+a[i];
        else {
            psum[i] = a[i];
        }
    // or partial_sum(begin(a),end(a),begin(psum)+1);
    return psum;
}

ll partialSum(vl nums, ll start, ll end) {
    vector<long long> ps = psum(nums);
    if (start == 0) {
        return ps[end];
    }
    return ps[end]-ps[start-1];
}

int main() {
    for (ll i: psum({1,2,3,4,5}))
        cout << i << " ";
    cout << "\n" << partialSum({1,2,3,4,5}, 1, 3);
    return 0;
}