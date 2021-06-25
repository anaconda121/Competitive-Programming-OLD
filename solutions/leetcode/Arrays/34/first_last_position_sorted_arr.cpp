// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array
// normal bsearch
// if find element and ur looking for first, eliminate right half of list by doing high = mid-1 and continue bsearch
// if ur looking for last, eliminate left half of list by doing low = mid+1 and continue bsearch
// u want to eliminate right and left halfs for diff tasks because for looking for first element it isn't going to be in the right half of the list b/c u want it to be as left as possible. and vice versa for last element 

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int first(vector<int> arr, int x, int n)
    {
        int low = 0, high = n - 1, res = -1;
        while (low <= high)
        {

            int mid = low+ (high-low) / 2;

            if (arr[mid] > x)
                high = mid - 1;
            else if (arr[mid] < x)
                low = mid + 1;

            // If arr[mid] is same as x, we
            // update res and move to the left
            // half.
            else
            {
                res = mid;
                high = mid - 1;
            }
        }
        return res;
    }

    int last(vector<int> arr, int x, int n)
    {
        int low = 0, high = n - 1, res = -1;
        while (low <= high)
        {

            int mid = low+ (high-low) / 2;

            if (arr[mid] > x)
                high = mid - 1;
            else if (arr[mid] < x)
                low = mid + 1;

            // If arr[mid] is same as x, we
            // update res and move to the right
            // half.
            else
            {
                res = mid;
                low = mid + 1;
            }
        }
        return res;
    }

    vector<int> searchRange(vector<int> nums, int target) {
        int f = first(nums, target, nums.size());
        int l = last(nums, target, nums.size());
        vector<int> ans = {f, l};
        return ans;
    }
};