#include <iostream>
#include <vector>
#include <string>

using namespace std;

void setIO(string name = "") { // name is nonempty for USACO file I/O
    ios_base::sync_with_stdio(0); cin.tie(0); // see Fast Input & Output
    // alternatively, cin.tie(0)->sync_with_stdio(0);
    freopen((name+".in").c_str(), "r", stdin); // see Input & Output
    freopen((name+".out").c_str(), "w", stdout);
}

int main() {
    setIO("substring");
    string s;
    cin >> s;
    int q;
    cin >> q;
    vector<int> l(q+1), r(q+1);
    for (int i = 1; i < q+1; ++i)
        cin >> l[i] >> r[i];

    vector<char> result(q);

    // your code

    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << endl;
    }

    return 0;
}