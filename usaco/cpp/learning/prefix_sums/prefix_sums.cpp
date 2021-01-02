/* Purpose of prefix sums
Let’s say we have an integer array arr with N elements, and we want to process Q queries
to find the sum of the elements between two indices a and b, inclusive, with different values
of a and b for every query. 
*/

// prefixsum[i] = psum[i] = psum[i-1]+a[i];, i > 0
// prefix sum of the 0th element of an array is the value of 0th element itself

//e.g. arr = [1,6,4,2,5,3]
// prefix sum arr = [1,7,11,13,18,21]
//if we want sum of elements from indices 1-5 (a,b respectively), we can do prefixsum[b]-prefixsum[a-1] --> known as partial sums
//queries are now in O(N+Q) instead of O(NQ)

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