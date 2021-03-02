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