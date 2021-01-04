#include <algorithm>
#include <vector>
#include <math.h>
#include <iostream>
#include <stdio.h>

using namespace std;

bool isPrime(int n) {
    if (n == 1) return false;
    for (int i = 2; i *i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    cout << isPrime(5) << endl; // 1== false
    cout << isPrime(12) << endl; //0 == true
    cout << isPrime(9) << endl;
    return 0;
}