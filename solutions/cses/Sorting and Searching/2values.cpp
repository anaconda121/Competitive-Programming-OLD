#include <bits/stdc++.h>

using namespace std;

int main(){
    int len, query;
    cin >> len >> query;
    vector<int> nums;   
    vector<int> clone;
    for (int i =0; i < len; i++) {
        int a;
        cin >> a;
        nums.push_back(a);
        clone.push_back(a);
    }
    sort(begin(nums),end(nums));
    //BSEARCH TIME
    long long low = 0;
    long long high = len -1;
    bool found = false;
    while (low < high) {
        long long sum = nums[low]+nums[high];
        if (sum < query) {
            low++; //since array is sorted, low needs to get higher
        } else if (sum > query){
            high--; //since array is sorted, high needs to reduce to make overall sum smaller
        } else if (sum == query) {
            auto it = find(clone.begin(), clone.end(), nums[high]);
	    long long idx1 = it-clone.begin();
            clone[idx1] = 0;
	    auto it2 = find(clone.begin(), clone.end(), nums[low]);   
	    cout << idx1 +1 << " " << (it2 - clone.begin())+1 << endl;
	    found = true;
            break;
        }
    }
    if (!found){
	cout << "IMPOSSIBLE" << endl;
    }	
    return 0;
}