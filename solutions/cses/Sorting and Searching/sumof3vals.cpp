//https://cses.fi/problemset/result/1862897/

//use 2p before search for target - arr[i].first

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second

bool cmp(pair<int,int> a, pair<int,int> b) {
	return a.first < b.first;
}

int main(){
	int n, x;
	cin >> n >> x;
	vector<pair<int,int>> arr;
	for (int i = 0; i < n; i++){
		int a;
		cin >> a;
		arr.push_back({a, i});
	}
	sort(arr.begin(), arr.end(), cmp);
	for (int i = 0; i < n; i++) {
		int left = 0;
		int right = n-1;
		int target = x - arr[i].f;
		while (left != right) {
			if (left != i && right != i && arr[left].f + arr[right].f == target) {
				cout << arr[i].s+1 << " " << arr[left].s+1 << " " << arr[right].s+1 << endl;
				return 0;
			} else if (arr[left].f + arr[right].f < target) {
				left++;
			} else {
				// not else if (arr[left].f + arr[right].f > target) b/c 2 nums cld equal x which wld not be included and wld cause tle
				right--;
			}		
		}
	}
	cout << "IMPOSSIBLE" << endl;
	return 0;
}