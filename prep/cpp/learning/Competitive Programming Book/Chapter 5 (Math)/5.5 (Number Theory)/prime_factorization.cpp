#include <bits/stdc++.h>

using  namespace std;

/*
O(sqrt(n)) b/c any number above sqrt(n) can be composed of any nums less than sqrt(n)
E.g. factoring 16 --> 16/8 works, but 8*8=64 and therefore will not be evalulated in for loop,
but 2^3=8, so 8 does not need to be evaluated due to while loop inside foor
E.g. factoring 15 --> this is where last if is needed, to capture 5 as a factor since 5*5 > 15
*/

vector<int> factor(int n){
    vector<int> factors;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }
    if (n > 1) {
        factors.push_back(n);
    }
    return factors;
}

int main(){
    return 0;
}