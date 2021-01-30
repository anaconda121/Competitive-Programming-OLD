#include <algorithm>
#include <vector>
#include <math.h>
#include <iostream>
#include <string>
#include <set>

using namespace std;

void setIO(string name, bool includeout=false) { // name is nonempty for USACO file I/O
    ios_base::sync_with_stdio(0); cin.tie(0); // see Fast Input & Output
    // alternatively, cin.tie(0)->sync_with_stdio(0);
    freopen((name+".in").c_str(), "r", stdin); // see Input & Output
    if (includeout) {
        freopen((name+".out").c_str(), "w", stdout);
    }
}

#define maxn 100005

int n, q;
string sequence;
char *colorArr;
int strokesZeroToI[maxn], strokesNToI[maxn];
set<char> colorSet;

void updateColorSet(char curr) {
    for (char c = curr; c <= 'Z'; c++) {
        colorSet.erase(c);
    }
    colorSet.insert(curr);
}

void calcStrokes(){
    int count = 0;
    for (int i = 0; i < n; i++) {
        char curr = colorArr[i];
        if (!colorSet.count(curr)) {
            count++;
        }
        updateColorSet(curr);
        strokesZeroToI[i] = count;
    }

    count = 0;
    colorSet.clear();
    for (int i = n-1; i >= 0; i--) {
        char curr = colorArr[i];
        if (!colorSet.count(curr)) {
            count++;
        }
        updateColorSet(curr);
        strokesNToI[i] = count;
    }
}

int getStrokesToI(int i){
    return (i < 0)?0:strokesZeroToI[i]; 
}

int getStrokesFromI(int i){
    return (i >= n)? 0: strokesNToI[i]; 
}

int main() {

    ios_base::sync_with_stdio(0); cin.tie(0); 
    // setIO("2", true);

    cin >> n >> q;
    cin >> sequence;
    colorArr = &sequence[0];

    calcStrokes();

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b; a--; b--;

        int count = getStrokesToI(a-1) + getStrokesFromI(b+1);

        cout << count << endl;
    }

    return 0;
}