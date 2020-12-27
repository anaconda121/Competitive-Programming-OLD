#include <iostream>
#include <vector>

using namespace std;

void setIO(string name = "") { // name is nonempty for USACO file I/O
    ios_base::sync_with_stdio(0); cin.tie(0); // see Fast Input & Output
    // alternatively, cin.tie(0)->sync_with_stdio(0);
    freopen((name+".in").c_str(), "r", stdin); // see Input & Output
    freopen((name+".out").c_str(), "w", stdout);
}

int main() {
    setIO("dist");
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; ++i)
        cin >> x[i] >> y[i];

    vector<int> f(n), s(n);

    // your code

    for (int i = 0; i < n; ++i) {
        cout << f[i] << ' ' << s[i] << endl;
    }

    return 0;
}