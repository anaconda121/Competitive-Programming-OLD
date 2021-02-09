#include <algorithm>
#include <vector>
#include <math.h>
#include <iostream>
#include <stdio.h>
#include <set>
#include <cstring>

using namespace std;

#define maxn 100005

void setIO(string name, bool includeout=false) { // name is nonempty for USACO file I/O
    ios_base::sync_with_stdio(0); cin.tie(0); // see Fast Input & Output
    // alternatively, cin.tie(0)->sync_with_stdio(0);
    freopen((name+".in").c_str(), "r", stdin); // see Input & Output
    if (includeout) {
        freopen((name+".out").c_str(), "w", stdout);
    }
}

int n,k;
int x[2*maxn], y[2*maxn], pos[maxn], lastPos[maxn], finalCounts[maxn];
set<int> visited [maxn];

void print(const int &i) {
    std::cout << i << ' ';
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); 
    memset(finalCounts, 0, sizeof(finalCounts));
    //setIO("1");

    cin >> n >> k;

    //cout << n << " " << k << endl; 

    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b; a--; b--;
        x[i] = a;
        y[i] = b;
        //cout << a << " " << b << endl;
    }

    //for_each(begin(x), end(x), print);

    for (int i = 0; i < n; i++) {
        pos[i] = i;
    }

    //simulate k moves
    for (int i = 0; i < k; i++) {
        int xCoord = x[i];
        int yCoord = y[i];

        int temp = pos[xCoord];
        pos[xCoord] = pos[yCoord];
        pos[yCoord] = temp;

        visited[temp].insert(yCoord);
        visited[pos[xCoord]].insert(xCoord);        

        lastPos[temp] = yCoord;
        lastPos[pos[xCoord]] = xCoord;
    }

    for (int i = 0; i < n; i++) {
        set<int> currCowsVisited;

        if (finalCounts[i] > 0) {
             continue;
        }

        if (visited[i].size() == 0) {
            finalCounts[i] = 1;
            continue;
        }

        set<int> locinthisseq;

        locinthisseq.insert(i);
        currCowsVisited.insert(visited[i].begin(), visited[i].end());

        int lastLoc = lastPos[i];
        while (lastLoc != i) {

            locinthisseq.insert(lastLoc);
            currCowsVisited.insert(visited[lastLoc].begin(), visited[lastLoc].end());

            lastLoc = lastPos[lastLoc];
        }

        int finalnum = currCowsVisited.size();
        for (int i : locinthisseq) {
            finalCounts[i] = finalnum;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << finalCounts[i] << endl;
    }


    return 0;
}