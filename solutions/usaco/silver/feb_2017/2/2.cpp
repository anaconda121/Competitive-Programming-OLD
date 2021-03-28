/*LOGIC
1. if broken, broken[a] = 1;
else it will default to 0
2. calc psums
3. finding subarray of min value that has length k
	a. in first iteration, sum of subarray from 0 - 6 (which is k for sample) can be represented by psums[i (starting at k)] - psums[i-k (0)]
	b. similar thing can be said for the rest of the subarrays
*/


#include <bits/stdc++.h>

using namespace std;

#define maxn 100005

int n, k ,b;
bool broken[maxn];
int psum[maxn];

int main() {
	freopen("maxcross.in", "r", stdin);
	freopen("maxcross.out", "w", stdout);
	cin >> n >> k >> b;
	for (int i = 0; i < b; i++) {
		int a;
		cin >> a;
		broken[a] = 1;
	}
	for (int i = 1; i <= n; i++){
		psum[i] = psum[i-1] + broken[i];
	}
	int ans = INT_MAX;
	for (int i = k; i <= n; i++) {
		ans = min(ans, psum[i] - psum[i-k]);
	}
	cout << ans << endl;
	return 0;
}