#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int len, query;
    cin >> len >> query;
    vector<int> nums;   
    for (int i =0; i < len; i++) {
        int a;
        cin >> a;
        nums.push_back(a);
    }
    sort(begin(nums),end(nums));
    //BSEARCH TIME
    int low = 0;
    int high = len -1;
    bool found = false;
    while (low < high) {
        int sum = nums[low]+nums[high];
        if (sum < query) {
            low++; //since array is sorted, low needs to get higher
        } else if (sum > query){
            high--; //since array is sorted, high needs to reduce to make overall sum smaller
        } else if (sum == query) {
            cout << nums[low] << " + " << nums[high] << " = " << query << endl;
            break;
        }
    }
    return 0;
}