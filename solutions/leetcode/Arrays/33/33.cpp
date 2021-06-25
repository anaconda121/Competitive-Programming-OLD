#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int res=-1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i]==target){
                res = i;
                return res;
            }
        }
        return res;
    }
};