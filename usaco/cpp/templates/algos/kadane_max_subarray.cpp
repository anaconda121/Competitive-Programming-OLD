#include <vector>
#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;
int arr[] = {-2,1,-3,4,-1,2,1,-5,4};

int maxSubarray() {
    int max_sum = arr[0];
    int curr = max_sum;
    for (int i = 1; i < (int)sizeof(arr)/sizeof(arr[0]); i++) {
        curr = max(arr[i] + curr, arr[i]);
        max_sum = max(max_sum,curr);
    }
    return max_sum;
}

int main(){
    cout << maxSubarray();
    return 0;
}