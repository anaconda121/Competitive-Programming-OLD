#include <deque>
#include <iostream>
#include <algorithm>

using namespace std;

/*
A deque stands for double ended queue and is a combination of a stack and a queue, in that it supports O(1)
insertions and deletions from both the front and the back of the deque

access elements of deque with [] notation like in arrays
*/

int main(){
    deque<int> d;
    d.push_front(3); // [3]
    d.push_front(4); // [4, 3]
    d.push_back(7); // [4, 3, 7]
    d.pop_front(); // [3, 7]
    d.push_front(1); // [1, 3, 7]
    d.pop_back(); // [1, 3]
    return 0;
}