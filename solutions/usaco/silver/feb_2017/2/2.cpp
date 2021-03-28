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