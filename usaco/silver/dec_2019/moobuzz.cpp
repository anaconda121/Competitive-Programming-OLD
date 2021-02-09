//http://www.usaco.org/index.php?page=viewproblem2&cpid=966


/* LOGIC 
a pattern repeats every 15 numbers 
so for a number n, whichever number in the first 8 it is a multiple off we need to find that
and then we can just * 15 by n-index i / 8 for ans
*/
#include <bits/stdc++.h>

using namespace std;

long long n;
long long ans = 0;
int arr[10];

void setIO(string name, bool includeout=false) { // name is nonempty for USACO file I/O
    ios_base::sync_with_stdio(0); cin.tie(0); // see Fast Input & Output
    // alternatively, cin.tie(0)->sync_with_stdio(0);
    freopen((name+".in").c_str(), "r", stdin); // see Input & Output
    if (includeout) {
        freopen((name+".out").c_str(), "w", stdout);
    }
}

int main() {
	setIO("moobuzz", true);
	cin >> n;
	arr[1]=1; arr[2] = 2; arr[3] = 4; arr[4] = 7; arr[5] = 8;
	arr[6] = 11; arr[7] = 13; arr[8] = 14;
	if (n <= 8) {
		ans = arr[n];
	} else {
		for (int i = 1; i <= 8; i++) {
			if ((n - i ) % 8 == 0) {
				ans = arr[i] + (15 * (n-i)/8);
			}
		}
	}
	cout << ans << endl;
}