// general info
//linear data struct
//simulates a queue at a store or a line
// FIFO 

//operations
//enqueue = adding elements to queuem, add elements to back of the queue
//dequeue = removing elements from queue, happens at the beginning of the queue

//complexity analysis
//enqueue - o(1)
//deqeue - o(1)
//peeking - o(1) = looking at value in front of queue
//contains - o(n)
//removal - o(n) = removing an element from the internal queue
//isempty - o(1)

#include <iostream>
#include <queue>

using namespace std;

// Print the queue
void showq(queue<int> gq){
    queue<int> g = gq;
    while (!g.empty()) {
        cout << '\t' << g.front();
        g.pop();
    }
    cout << '\n';
}

int main()
{
    queue<int> gquiz;
    gquiz.push(10);
    gquiz.push(20);
    gquiz.push(30);
 
    cout << "The queue gquiz is : ";
    showq(gquiz);
 
    cout << "\ngquiz.size() : " << gquiz.size();
    cout << "\ngquiz.front() : " << gquiz.front();
    cout << "\ngquiz.back() : " << gquiz.back();
 
    cout << "\ngquiz.pop() : ";
    gquiz.pop();
    showq(gquiz);

    if (gquiz.empty()) { 
        cout << "True"; 
    } 
    else { 
        cout << "False"; 
    } 

    return 0;
}