#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

using namespace std;

int main() {
    map<int,int> A; 
    //key value pair, value in [] is key, val after equal sign is value
    A[1] = 100;
    A[2] = -1;
    A[3] = 200;

    //traversing map
    for (map<int,int>::iterator it = A.begin(); it != A.end(); it++) {
        cout << it->first << " => " << it->second << endl;
    }

    //getting size of map
    cout << A.size() << endl;

    //clearing map
    A.clear();
    cout << A.size() << endl;

    //inserting values into map using pairs
    A.insert(pair<int,int>(1,1)); //inserts are only used for creating key-value pair, not updating
    A.insert(pair<int,int>(3,1));
    A.insert(pair<int,int>(1,2));

    //mass-adding values into map
    map<char,int> count;
    string x = "tanish tyaagi";
    for (char c : x) {
        count[c]++;
    }  
    cout << count['a'] << " " << count['z'] << " " << endl;  
    return 0;
}