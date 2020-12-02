#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

int n, a[100], b[100], g[100];

int optimal (int i) 
{   
    int count = 0;
    int location = i;
    for (int i = 0; i < n; i++) {
        if (a[i] == location) {
            location = b[i];
        } else if (b[i] == location) {
            location = a[i];
        } //if none location should stay same
        if (location == g[i]) {
            count++;
        }
    }
    return count;
}

int main() 
{
    ifstream in ("shell.in");
    ofstream out ("shell.out");
    in >> n;
    for (int i = 0; i < n; i++) {
        in >> a[i] >> b[i] >> g[i];
    }
    int high = 0;
    for (int i = 1; i <= 3; i++) {
        high = max(high, optimal(i));
    }
    out << high <<endl;
    return 0;
}