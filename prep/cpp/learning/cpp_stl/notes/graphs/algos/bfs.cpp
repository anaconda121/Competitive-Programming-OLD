#include <algorithm>
#include <vector>
#include <math.h>
#include <iostream>
#include <queue>

using namespace std;

/*BFS
    GOATED ANIMATION --> https://csacademy.com/lesson/breadth_first_search/

    Start by visiting one arbitrary vertex, which we call the root.
    Visit all the root's neighbours and push them into a queue.
    Pop the first node from the queue, visit all its neighbours and push into the queue those neighbours that have not been previously visited.
    Repeat step 3 while the queue is not empty.
    Finally, when the queue becomes empty it means all the reachable nodes have been visited, so the algorithm finishes.
*/

vector<int> adj_list[100];
bool visited[100];

void bfs (int start) {
    queue<int> q;
    q.push(start);
    while (!q.empty()) {
        //if q is empty than traversal is done
        int curr = q.front();
        q.pop();
        for (int i : adj_list[curr]) {
            if (!visited[i]) {
                //adding new element to queue and marking it as true 
                //so we don't go back to it again
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

int main(){
    //CREATE ADJ LISTS
    return 0;
}