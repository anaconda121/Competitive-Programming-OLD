#include <iostream>
#include <queue>

using namespace std;

int main(){
    priority_queue <int, vector<int>, greater<int> > pq; // creates min pq 
    pq.push(5);
    pq.push(1);
    pq.push(10);
    pq.push(30);
    pq.push(20);
 
    // One by one extract items from min heap
    while (pq.empty() == false){
        cout << pq.top() << " ";
        pq.pop();
    }
    return 0;
}