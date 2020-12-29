// https://www.youtube.com/watch?v=r7P9sy5Rar8&list=PLIY8eNdw5tW_zX3OCzX7NJ8bL1p6pWfgG&index=5&ab_channel=SimpleSnippets

// behaves like an irl stack
// E.g. there is a stack of books. if u want to get 1st book, you have to remove all the books above it.
// LIFO - last in first out
// has a predefined amt of data
// linear - data is stored in a particlar manner

// data that is inserted first goes to bottom of stack, data that is inserted last goes to top. this is why it is lifo
// only 1 way entry and release in stack

//stack operations
/*
1. push - place an item onto stack -- if no place, get stack overflow error
2. pop - return the item at the top of the stack and then remove it. if pop is called when stack is empty, stack is in underflow state
3. isempty - tells whether stack is empty or no
4. isfull - checks if stack is full or not
5. count - gets num items in stack
6. change - change item at the ith position
7. peek - access item at the ith position
8. emplace - pass in an element that gets adde to the top of the stack, emplace is more efficent for larger data types
*/

//complexity analysis
// pushing - o(1)
// popping - o(1)
// peeking - o(1)
// searching - o(n)
// size - o(1)

#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

/* printing elements in stack */
void showstack(stack <int> s) 
{ 
    while (!s.empty()) 
    { 
        cout << '\t' << s.top(); 
        s.pop(); 
    } 
    cout << '\n'; 
} 

int main(){
    //declaring stack
    stack<int> s;

    //adding elements to stack w/ push
    s.push(10);
    s.push(11);
    s.push(12);
    s.push(13);
    s.emplace(14); //insertion using emplace

    //displaying stack
    showstack(s);

    // stack stats
    cout << "\ns.size() : " << s.size(); 
    cout << "\ns.top() : " << s.top(); 

    //deleting element
    s.pop(); 
    cout << "\n";
    showstack(s); 

    cout << "\n" << s.empty();

    //swapping elements of a stack
    stack<int> s2;
    s2.push(15);
    s2.push(16);
    s2.push(17);

    s.swap(s2);

    cout<<"mystack1 = "; 
    showstack(s); 

    cout<<"mystack2 = ";
    showstack(s2); 

    return 0;
}