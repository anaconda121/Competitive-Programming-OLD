#include <algorithm>
#include <vector>
#include <math.h>
#include <iostream>

using namespace std;

/* adj lists
The other common way of representing graphs is using adjacency lists. For each node ii, we store an array of its neighbours. 
In the case of directed graphs, we will only store in the array those nodes jj with the property that the arc (i, j)(i,j) exists.
These nodes are called outgoing neighbours of node ii.

(LOOK AT adj_lists.png)
*/

class Graph {
    int N; //num of edges
    vector<int> *adj; //adjacency list

    public:
        Graph(int N) {
            this-> N = N;
            adj = new vector<int>[N];
        }

        void addEdge(int x, int y) {
            //1. assuming that edge is undirected (bidirectional)
            //2. assuming that values in tree go from 0 - (n-1)
            adj[x].push_back(y); //y is adj to x
            adj[y].push_back(x); //x is adj to y
        }

        void printAdjList() {
            for (int i = 0; i < N; i++) {
                cout << "Vertex: " << i << "-->";
                for (int j : adj[i]) {
                    cout << j << " ,";
                }
                cout << "\n";
            }
        }
};

int main() {
    Graph g(4);
    // all edges are undirected
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(2,3);
    g.addEdge(1,2);
    g.printAdjList();
    return 0;
}