//https://codeforces.com/contest/279/problem/B

/*
sample case:

3 1 2 1

3 + 1 + 2 = 6 > 5
subtract 3, 1 + 2 + 1 = 4 < 5 so we are good

goal is to find largest subarray that sums to t
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, t;	
	cin >> n >> t;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int pointer = 0;
	int sum = 0;
	int count = 0;
	for (int i = 0; i < n; i++) {
		sum += arr[i];
		if (sum <= t) {
			count++;
		} else {
			sum -= arr[pointer];
			pointer++;
		}
	}
	cout << count << endl;
	return 0;
}