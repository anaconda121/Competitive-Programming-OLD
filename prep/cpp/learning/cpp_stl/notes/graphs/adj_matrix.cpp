#include <bits/stdc++.h>

using namespace std;
#define N 4 // num nodes in graph

/* PRO-CON 
Advantages
Edge lookup, i.e. checking if a particular edge exists, is done easily.
Adding new edges, or deleting existing ones, is also straightforward.
If the graph is dense, i.e. the number of edges is large. This is usually the preferred method of representing the graph.
Certain algorithms are easier to implement using an adjacency matrix. 

Disadvantages
The memory allocated is always an N * NN∗N matrix, even in the case of sparse graphs, i.e. the number of edges is small.
For a given node finding all its neighbours, i.e. other nodes that share an edge with it, requires checking an entire row of elements in the matrix.
*/

void addEdge(int graph[N][N], int u, int v){
    //1. assuming that edge is undirected (bidirectional)
    //2. assuming that values in tree go from 0 - (n-1)
    graph[u][v] = 1; // u is adj to v
    graph[v][u] = 1; // v is adj to u
}

void printAdjMatrix(int graph[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << graph[i][j] << " , ";
        }
        cout << "\n";
    }
}

int main(){
    int adj_matrix[N][N] = {0};
    addEdge(adj_matrix, 0, 1);
    addEdge(adj_matrix, 0, 3);
    addEdge(adj_matrix, 1, 3);
    addEdge(adj_matrix, 1, 2);
    addEdge(adj_matrix, 2, 3);
    printAdjMatrix(adj_matrix);
    return 0;
}
