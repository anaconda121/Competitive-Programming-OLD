#include <iostream>
#include <algorithm>
#include <tuple>

using namespace std;

int main() {
    //tuples allow u to create an array of unlimited values. dont have to be limited
    tuple<int,int,int> t = make_tuple(3,4,5); //delcaring tuple
    cout << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << endl; //printing out specific values of a tuple
    get<0>(t) = 7; //modifying value of a tuple
    cout << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << endl;

    tuple<string, string, int> tp2 = make_tuple("Hello", "world", 100);
    string s1, s2; int x; 
    tie(s1, s2, x) = tp2; //assigning values of a tuple to other variables 
    cout << s1 << " " << s2 << " " << x << endl;
    return 0;
}