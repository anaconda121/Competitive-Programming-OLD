#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

using namespace std;

int main() {
    map<int,int> A;
    A[1] = 100;
    A[2] = -1;
    A[3] = 200;

    map<char,int> count;
    string x = "tanish tyaagi";
    for (char c : x) {
        count[c]++;
    }  
    cout << count['a'] << " " << count['z'] << " " << endl;  

    return 0;
}