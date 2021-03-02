/* general info */

// list of nodes tht hold data that point to other nodes which contain data
// singly linked list: data - > data - > null, notice last element points to null

// head - first node in list
// tail - last node in list
// node - object containing data and pointer to another node
// ref. to head and tail is always maintained as this helps with quick additions and removals from both ends of the list

/* diff between singly and doubly linked list */
// singly list only contain pointer to next node
// doubly linked list holds pointer to prior node and next node

/* pros and cons */ 
// singly lined use less memory, easier to implemtn, cons is that u can't easily access prev. elements
// doubly linked can be transversed backwords, but take 2x memory 

//complexity analysis

//note: first vals are for singly linked list, second are for doubly linked list
//searching - o(n) , o (n)
//insert at head - o(1), o(1)
//remove head- o(1), o(1)
//remove at tail - o(n), o(1)
//remove in middle - o(n), o(n)

#include <iostream> 
#include <list> 

using namespace std; 
  
//function for printing the elements in a list 
void showlist(list <int> g) 
{ 
    list <int> :: iterator it; 
    for(it = g.begin(); it != g.end(); ++it) 
        cout << '\t' << *it; 
    cout << '\n'; 
} 
  
int main() 
{ 
  
    list <int> gqlist1, gqlist2; 
  
  
    for (int i = 0; i < 10; ++i) 
    { 
        gqlist1.push_back(i * 2); 
        gqlist2.push_front(i * 3); 
    } 

    //another way of adding elements to list using assign
    gqlist1.assign(5,100); //adds 5 100's to the end of list

    cout << "\nList 1 (gqlist1) is : "; 
    showlist(gqlist1); 
  
    cout << "\nList 2 (gqlist2) is : "; 
    showlist(gqlist2); 
  
    cout << "\ngqlist1.front() : " << gqlist1.front(); 
    cout << "\ngqlist1.back() : " << gqlist1.back(); 
  
    cout << "\ngqlist1.pop_front() : "; 
    gqlist1.pop_front(); 
    showlist(gqlist1); 
  
    cout << "\ngqlist2.pop_back() : "; 
    gqlist2.pop_back(); 
    showlist(gqlist2); 
  
    cout << "\ngqlist1.reverse() : "; 
    gqlist1.reverse(); 
    showlist(gqlist1); 
  
    cout << "\ngqlist2.sort(): "; 
    gqlist2.sort(); 
    showlist(gqlist2); 
    
    //inserting elements into list
    auto it = gqlist2.begin();
    advance(it,2);    // iterator to point to 3rd position, advances iterator 2 indexes
    gqlist2.insert(it,5);
    showlist(gqlist2);
    // using insert to insert 
    // 2 element at the 4th position 
    // inserts 2 occurrences 
    // of 7 at 4th position 
    gqlist2.insert(it, 2, 7); 

    //deleting elements from list
    gqlist1.erase(it);
    //erasing range of elements
    auto it2 = gqlist1.begin();
    advance(it2,2);
    gqlist1.erase(it,it2); // pass in 2 iterators (first for 1st index, second for last index)

    //deleting elements using remove
    gqlist1.remove(20); //removes all elements with val 20

    return 0; 
  
}