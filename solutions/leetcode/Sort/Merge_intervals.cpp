#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define f first
#define s second

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> merged;
    for (auto interval : intervals) {
        if (merged.empty() || merged.back()[1] < interval[0]) {
            merged.push_back(interval);
        }

        else {
            merged.back()[1] = max(merged.back()[1], interval[1]);
        }
    }
    return merged;
}

int main(){
    vector<vector<int>> vec{{ 1,4 }, 
                            { 0,2 },
                            { 3,5 },
                            // { 15,18 } 
                         }; 
    vector<vector<int>> ans = merge(vec);
    for (int i = 0; i < ans.size(); i++){
        for (int j = 0; j < ans[i].size(); j++){
            cout << ans[i][j] << " , "; 
        }
        cout << endl;
    }
    return 0;
}