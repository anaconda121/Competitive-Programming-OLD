#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, x;
	cin >> n >> x;
	int arr[n];
	for (int i = 0; i < n; i++){
		cin >> arr[i];
	}
	long long sum = 0;
	long long ans = 0;
	for (int left = 0, right = 0; right < n; right++){
		sum += arr[right];
		while (sum > x) {
			sum -= arr[left];
			left++;
		}
		if (sum == x) {
			ans++;
		}
	} 
	cout << ans << endl;
	return 0;
}