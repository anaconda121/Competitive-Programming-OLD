#include <iostream>
#include <vector>

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

int main() {
    int M = 4;
    vector<Edge> v;
    for (int i = 0; i < M; ++i) {
        int a,b,w; 
        cin >> a >> b >> w;
        v.push_back({a,b,w});
    }
    cout << "\n";
    for (Edge e: v)  {
        cout << e.a << " " << e.b << " " << e.w << "\n";
    }
    return 0;
}