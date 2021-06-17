//https://leetcode.com/problems/container-with-most-water/submissions/
//basic 2 pointers
//start 1 pointer at 0 and one at n-1
//calc area
//if h.left < h.right, l++, else r--
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define f first
#define s second

void setIO(string name = "", bool includeout = false) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((name+".in").c_str(), "r", stdin);
    if (includeout)
        freopen((name+".out").c_str(), "w", stdout);
}

int maxArea(vector<int>& height) {
    int left = 0;
    int right = height.size()-1;
    int maxArea = -1;
    while (left < right) {
        int h = min(height[left], height[right]);
        int l = right - left;
        int area = l * h;
        if (area > maxArea){
            // cout << "right: " << right << endl;
            // cout << "left: " << left << endl;
            maxArea = area;
        }
        if (height[left] > height[right]) {
            right--;
        } else if (height[left] < height[right]) {
            left++;
        } else {
            if (height[left+1] > height[right-1]) {
                left++;
            } else if (height[left+1] < height[right-1]) {
                right--;
            } else {
                left++;
            }
        }
    }
    return maxArea;
}

int main() {
    vector<int> h {1,1};
    cout << maxArea(h) << endl;
    return 0;
}
