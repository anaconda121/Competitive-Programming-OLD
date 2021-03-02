#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
    int n,t;
    cin >> n >> t;
    vector<ll> m (n);
    for (int i = 0; i < n; i++) {
        cin >> m[i];
    }
    ll low = 0;
    ll high = 1E18;
    ll ans = 0;
    while (low <= high) {
        ll curr_guess = (low+high)/2;
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            sum += curr_guess/m[i]; //how many products machine can produce in curr_guess time
            if (sum >= t) {
                break; 
            } 
        }
        if (sum >= t) {
            ans = curr_guess;
            high = curr_guess-1; //need to get lower
        } else {
            low = curr_guess+1; //need to get higher
        }
    }
    cout << ans << endl;
    return 0;
}