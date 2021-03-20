#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, t;	
	cin >> n >> t;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	int sum = 0;
	long long count = 0;
	int idx = 0;
	while (sum < t) {
		sum += arr[idx];
		if (sum == t) {
			break;
		}
		idx++;
		count++;
	}
	cout << count << endl;
	return 0;
}

1 1 2 2 3 4