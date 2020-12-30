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
    priority_queue<int> gquiz;
    gquiz.push(10);
    gquiz.push(30);
    gquiz.push(20);
    gquiz.push(5);
    gquiz.push(1);
    //you can also do emplace instead of push, emplace is better for pq's of bigger data structures
 
    cout << "The priority queue gquiz is : ";
    showpq(gquiz);
 
    cout << "\ngquiz.size() : " << gquiz.size();
    cout << "\ngquiz.top() : " << gquiz.top();
 
    cout << "\ngquiz.pop() : ";
    gquiz.pop();
    showpq(gquiz);

    priority_queue<int> gquiz2;
    gquiz2.push(14);
    gquiz2.push(13);
    gquiz2.push(12);
    gquiz2.push(11);
    gquiz2.push(10);
    gquiz.swap(gquiz2);

    showpq(gquiz);
    cout << "\n";
    showpq(gquiz2);
    return 0;
}