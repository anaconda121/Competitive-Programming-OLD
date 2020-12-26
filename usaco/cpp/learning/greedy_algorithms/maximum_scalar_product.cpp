#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int maximum_scalar_productslow(vector<int> a, vector<int> b) {
    sort(begin(a), end(a));
    sort(begin(b), end(b));
    int sum = 0;
    for (int i = 0; i < a.size(); i++) {
        sum += a[i]*b[i];
    }
    return sum;
}

//O(n^2)
int maximum_scalar_product(vector<int> a, vector<int> b) {
    int ans = 0;
    while (a.size()> 0) {
        auto it = max_element(begin(a), end(a));
        auto it2 = max_element(begin(b), end(b));
        ans += *it * *it2;
        a.erase(it);
        b.erase(it2);
    }
    return ans;
}

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
    int sum1 = maximum_scalar_product(a,b);
    int sum2 = maximum_scalar_productslow(a,b);
    cout << sum1 << " , " << sum2 << endl;
}