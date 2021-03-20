//http://www.usaco.org/index.php?page=viewproblem2&cpid=738
#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second

vector<pair<long long, long long>> cows;

bool cmp(pair<long long, long long> a, pair<long long, long> b) {
	return a.s < b.s;
}

int main() {
	freopen("pairup.in", "r", stdin);
	freopen("pairup.out", "w", stdout);
	long long n = 0;
 	cin >> n;
	long long freq[n+1];
	long long total = 0;
	for (int i = 0; i < n; i++) {
		long long x, y;
		cin >> x >> y;
		cows.push_back({x, y});
		total += x;
	}
	sort(cows.begin(), cows.end(), cmp);
	freq[0] = 0;
	for (int i = 1; i <= n; i++) {
		freq[i] = freq[i-1] + cows[i-1].f;
		//cout << i << " " << freq[i-1] << "    " << cows[i-1].f << "\n";
	}
	//long long total = freq[n-1] + cows[n-1].f;
	//cout << total << endl;
	long long ans = cows[0].s + cows[n - 1].s;

	long long currIdx = n-1;
	for (long long i = 1; i <= currIdx; i++) {
		long long pos = total - 1 - freq[i];
		while (currIdx >= 0 && freq[currIdx] > pos) {
			currIdx--;
		}
		//cout << "there2222\n";
		ans = max(ans, cows[i].s + cows[currIdx].s);
	}
	cout << ans << endl;
	return 0;
}