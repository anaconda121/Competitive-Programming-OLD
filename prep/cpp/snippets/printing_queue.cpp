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

int main(){
    queue<int> gquiz;
    gquiz.push(10);
    gquiz.push(20);
    gquiz.push(30);
    
    // We can also use front and back as
    // iterators to traverse through the queue
    cout << "Using iterators : ";
    for (auto i = gquiz.front(); i != gquiz.back(); i++) {
        cout << i << " ";
    }
    return 0;
}