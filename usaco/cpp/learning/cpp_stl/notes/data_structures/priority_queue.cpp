//general info
//queue except that each element has a priority and the element that comes out of the queue first has the highest priority
//support comparable data, meaning that the data inserted into queue has to be able to be ordeered from least-greatest

// max and min pq
// max pq has larger elements w/ higher priority
// min pq has smaller elements w/ higher priority

// cpp by default shows a max pq


//time complexities
// naive removing - o(n)
// advanced removing w/ hash table = o(log(n))
// naive contains - o(n)
// contains check w/ hash table - o(1)

#include <iostream>
#include <queue>

using namespace std;

void showpq(priority_queue<int> gq)
{
    priority_queue<int> g = gq;
    while (!g.empty()) {
        cout << '\t' << g.top();
        g.pop();
    }
    cout << '\n';
}

int main(){

    return 0;
}