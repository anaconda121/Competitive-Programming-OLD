#include <bits/stdc++.h>

using namespace std;

/* O(log(n)) */
/* gcd of multiple elements
    gcd(a_1, gcd(a_2, gcd(a_3,a_4)))
*/
int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

int lcm(int a, int b){
    return (a*b) / gcd(a,b);
}

int main(){
    return 0;
}