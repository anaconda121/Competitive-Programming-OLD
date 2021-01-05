#include <algorithm>
#include <vector>
#include <math.h>
#include <iostream>
#include <stdio.h>

using namespace std;

int nums[102];

void sieve() {
    int maxN = 100;
    for (int i = 1; i <= maxN; i++) {
        nums[i] = 1;
    }
    nums[0] = nums[1] = 0;
    for (int i = 2; i <= maxN; i++) {
        if (nums[i]) {
            for (int j = i*i; j <= maxN; j+=i) {
                nums[j] = 0;
            }
        }
    }
    for (int element : nums) {
        cout << element << " , ";
    }
    cout << "\n";
    
}

int main() {
    sieve();    
    return 0;
}