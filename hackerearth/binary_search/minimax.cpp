#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*void setIO(string name = "") { // name is nonempty for USACO file I/O
    ios_base::sync_with_stdio(0); cin.tie(0); // see Fast Input & Output
    // alternatively, cin.tie(0)->sync_with_stdio(0);
    freopen((name+".in").c_str(), "r", stdin); // see Input & Output
    freopen((name+".out").c_str(), "w", stdout);
}*/

int main(){
    //setIO("minimax");
    vector<long long> nums (5);
    for (int i = 0; i < 5; i++) {
        cin >> nums[i];
    }
    std::sort(nums.begin(), nums.end());
    //for (auto element: nums) {
    //    std::cout << element << " ";
    //}
    long long min = nums[0] + nums[1] + nums[2] + nums[3];
    long long max = nums[1] + nums[2] + nums[3] + nums[4];
    std::cout << (long) min << " " << (long) max << endl;
    return 0;
}