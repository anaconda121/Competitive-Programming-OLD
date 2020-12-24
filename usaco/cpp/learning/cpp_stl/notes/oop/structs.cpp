#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//struct is the same thing as a class, but its members are all public by default
struct Edge {
    int a,b,w;
};

//equivalent code with a class
/*class Edge {
    public:
        int a,b,w;
};*/

//comparator for sorting vector of edges, we choose to sort by w from least to greatest for this example
bool cmp(const Edge& x, const Edge& y) { 
    return x.w < y.w; 
    //return x.w > y.w for w from greatest - least
}

//comparator that has 2 criteria
//this applies to an arbitary amount of criteria
bool cmp2(const Edge& x, const Edge& y) {
    if (x.w != y.w) {
        return x.w < y.w; 
    }
    //if weights are equal, we go to parameter a for "tiebreaker"
    return x.a < y.a;
}

void setIO(string name = "") { // name is nonempty for USACO file I/O
    ios_base::sync_with_stdio(0); cin.tie(0); // see Fast Input & Output
    // alternatively, cin.tie(0)->sync_with_stdio(0);
    freopen((name+".in").c_str(), "r", stdin); // see Input & Output
    freopen((name+".out").c_str(), "w", stdout);
}

int main() {
    setIO("struct");
    int M = 4;
    vector<Edge> v;
    for (int i = 0; i < M; ++i) {
        int a,b,w; cin >> a >> b >> w;
        v.push_back({a,b,w});
    }
    //sort(begin(v),end(v),cmp);
    sort(begin(v), end(v), cmp2);
    for (Edge e: v) { 
        cout << e.a << " " << e.b << " " << e.w << "\n";
    }
}