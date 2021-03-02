#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
/* LOGIC
we start both pointers at the left, and the pointers mark the beginning and end of
the subarray we are currently checking. We advance the right pointer one step to the right if
the total of the current subarray is too small, advance the left pointer one step to the right if
the current total is too large, and we are done when we find the correct total.
*/
int main(){
    int len, query;
    cin >> len >> query;
    vector<int> nums;   
    for (int i =0; i < len; i++) {
        int a;
        cin >> a;
        nums.push_back(a);
    }
    int left = 0; int right = 0; int sum = nums[0];
    for(right = 0; right < len; right++){
        if (right > 0) {
            sum += nums[right];
        }
        while(sum > query && left < right){
            sum -= nums[left];
            left++;
        }
        if(sum == query){
            cout << sum << endl;
            break;
        }
    }
    return 0;
}