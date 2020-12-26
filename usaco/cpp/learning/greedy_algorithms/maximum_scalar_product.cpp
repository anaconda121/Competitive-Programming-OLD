#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a (n);
    vector<int> b (n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    sort(begin(a), end(a));
    sort(begin(b), end(b));
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i]*b[i];
    }
    cout << sum << endl;
    return 0;
}