#include <algorithm>
#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

/* edge list 
An edge list contains all edges of a graph in some order. This is a convenient
way to represent a graph if the algorithm processes all edges of the graph and it
is not needed to find edges that start at a given node.
*/

vector<pair<int,int>> edges; //non-weighted
vector<tuple<int,int,int>> weighted_edges; //weighted

void addEdge(int x, int y){
    edges.push_back(make_pair(x,y));
    // edges.push_back(make_pair(y,x)); --> if graph is undirected
}

void printEdgeList() {
    for (auto element : edges) {
        cout << "first node: " << element.first << " , second node: " << element.second << endl;
    }
}

void addWeightedEdge(int x, int y, int w) {
    weighted_edges.push_back(make_tuple(x, y, w));
    //weighted_edges.push_back(make_tuple(y,x, w)); if graph is undirected
}

void printEdgeListWeighted() {
    for (auto element : weighted_edges) {
        cout << "first node: " << get<0>(element) << " , second node: " << get<1>(element) << "  , weight: " << get<2>(element) << endl;
    }
}

int main(){
    // non-weighted graphs
    edges.push_back({1,2});
    edges.push_back({2,3});
    edges.push_back({2,4});
    edges.push_back({3,4});
    edges.push_back({4,1});
    printEdgeList();

    cout << "\n";

    //weighted-graphs
    weighted_edges.push_back({1,2,5});
    weighted_edges.push_back({2,3,7});
    weighted_edges.push_back({2,4,6});
    weighted_edges.push_back({3,4,5});
    weighted_edges.push_back({4,1,2});
    printEdgeListWeighted();
    return 0;
}