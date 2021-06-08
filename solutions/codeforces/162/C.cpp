#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define f first
#define s second

void setIO(string name = "", bool includeout = false) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((name+".in").c_str(), "r", stdin);
    if (includeout)
        freopen((name+".out").c_str(), "w", stdout);
}

vector<int> factor(int n) {
	vector<int> ret;
	for (int i = 2; i * i <= n; i++) {
		while (n % i == 0) {
			ret.push_back(i);
			n /= i;
		}
	}
	if (n > 1) ret.push_back(n);
	return ret;
}

int main() {
    int n;
    cin >> n;
    vector<int> ret = factor(n);
    for (int i = 0; i < ret.size(); i++) {
        if (i < ret.size()-1){
            cout << ret[i] << "*";
        }else{
            cout << ret[i];
        }
    }
    return 0;
}
