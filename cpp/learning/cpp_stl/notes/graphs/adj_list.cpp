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

/*PRO=CON 
Advantages
For a graph with NN nodes and MM edges, the memory used depends on M. This makes the adjacency lists ideal for storing sparse graphs.
Let's assume we have a directed graph with 5\ 0005 000 nodes and (only) 10\ 00010 000 edges. In the case of the adjacency matrix, we would have allocated 25\ 000\ 00025 000 000 elements, whereas in the case of adjacency lists we only need 10\ 00010 000.
For a given node finding all its neighbours requires checking only the node's list which contains a numbers of elements equal to the number of neighbours (one per neighbour).
Adding an edge can be done easily, by appending the neighbour(s) in the corresponding list(s).

Disadvantages
Edge lookup is slow, in the worst case being necessary to traverse all the elements of a node's list.
Erasing an edge is just as slow as the lookup.
If the graph is dense, the adjacency lists are probably not as good as an adjacency matrix.
Implementing them is slightly more difficult than an adjacency matrix. Even so, we still recommend them in most of the cases.
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