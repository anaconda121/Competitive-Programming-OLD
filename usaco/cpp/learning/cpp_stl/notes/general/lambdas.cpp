#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

/* lambas are ways to write functions w/o formally declaring a function 
    good for one-liners
    pass in lambas to another functions
    E.g. function<bool(int)>f  --> note function keyword, need to include functional for this as well
*/

// function to get max value of x sch that f(X) function is true
// 1st case: f(X) always returns true, so that means that the hi val (10) is the max
// 2nd case: f(x) returns true as long as x^2 <= 30, so 5 is max val b/c 6^2 = 36
// 3rd case: f(X) always is false, so none of the values work, meaning that the max val has to be less than lo, so 2-1 = 1
int lstTrue(function<bool(int)>f, int lo, int hi) {
    int res = lo-1;
    while (lo <= hi) {
        int mid = (lo+hi)/2; // find the middle of the current range
        if (f(mid)) {
            // if mid works, then all numbers smaller than mid also work
            // so we only care about the part after mid
            res = mid; // update the answer
            lo = mid+1; // cut the part before mid
            // notice that we already handled mid itself so we cut it as well
        } else {
            // if mid does not work, greater values would not work too
            // so we don't care about them
            hi = mid-1; // cut mid and after
        }
    }
    // now res is the answer
    // if res is lo-1 that means no value in the range satisfies the condition
    return res;
}

int main() {
    cout << lstTrue([](int x) { return true; },2,10) << "\n"; //lamba function f needs an int and return bool, therefore int x is the int
                                                      //return true is bool, note the [] before call
                                                      //if we want to pass external variables in, we can use [=] to pass by value and [&] to pass by ref
    cout << lstTrue([](int x) { return x*x <= 30; },2,10) << "\n"; // 5
    cout << lstTrue([](int x) { return false; },2,10) << "\n"; // 1
    return 0;
}