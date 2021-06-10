#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define f first
#define s second

void setIO(string name = "", bool includeout = false) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((name+".in").c_str(), "r", stdin);
    if (includeout)
        freopen((name+".out").c_str(), "w", stdout);
}

int main() {
    cout << bitset<32>(43) << endl;
    cout << bitset<32>(-43) << endl;
    cout << endl;

    //binary representation for any number
    int y = 18;
    for (int i = 31; i >= 0; i--) {
        if (y&(1<<i)) {
            cout << "1";
        }
        else cout << "0";
    }
    cout << endl;

    //built-in bit functions
    int x = 5328; // 00000000000000000001010011010000
    cout << __builtin_clz(x) << "\n"; // 19
    cout << __builtin_ctz(x) << "\n"; // 4
    cout << __builtin_popcount(x) << "\n"; // 5
    cout << __builtin_parity(x) << "\n"; // 1
    cout << endl;

    //implemnting set with bit operations
    int z = 0;
    z |= (1<<1); //adding 1
    z |= (1<<3); //adding 3
    z |= (1<<4); //adding 4
    z |= (1<<4); //already 1, so stays 1, justifying the representation of a set
    z |= (1<<8); //adding 8
    cout << __builtin_popcount(z) << "\n"; // 4
    for (int i = 0; i < 32; i++) {
        if (z&(1<<i)) cout << i << " ";
    }
    cout << endl;

    /*
    Set Operations
    intersection : a & b
    union : a | b
    complement : ~a
    difference : a & (~b)
    */

    //intersection
    // set that has all elements that belong to a and b
    // justifies using & operator

    // union
    // set that has all elements that being to a or b
    int a = (1<<1)|(1<<3)|(1<<4)|(1<<8); // {1,3,4,8}
    int b = (1<<3)|(1<<6)|(1<<8)|(1<<9); // (1,3,6,8,9)
    int c = a|b; // merge them, while only having unique vals
    cout << __builtin_popcount(c) << "\n"; // 6
    for (int i = 0; i < 32; i++) {
        if (c & (1 << i)) {
            cout << i << " ";
        }
    }
    cout << "\n\n";

    //complement
    //involves only 1 set, set of all elements in universal set that are not in a
    //for ints, universal set is defined as {1,2...,31}
    int d = (1<<6)|(1<<3);
    int e = ~d;
    cout << __builtin_popcount(e) + __builtin_popcount(d) << endl;
    for (int i = 0; i < 32; i++) {
        if (e & (1 << i)) {
            cout << i << " ";
        }
    }
    cout << endl;

    //difference
    //set of all elements that are in a but not in  b
    // a & (~b) works b/c all the 1's in b after ~b would be where b does not have a value
    // and & operator finds all positions where a and b both have 1's, so this is perfecto
    return 0;
}
