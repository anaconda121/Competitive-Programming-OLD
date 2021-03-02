#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

//another way of binary searching for a number

/* 
    syntax for ternary operator: condition ? (outcome if condition is met) : (code if condition is not met)
*/
int lstTrue(function<bool(int)> f, int lo, int hi) {
    for (lo --; lo < hi; ) {
        int mid = (lo+hi+1)/2;
        f(mid) ? lo = mid : hi = mid-1;
        // condition is f(mid) == true
        //if f(mid) == true, then outcome is  lo = mid
        // else outcome is hi = mid - 1
    }
    return lo;
}