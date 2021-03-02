#include <bits/stdc++.h>

using namespace std;

#define maxn 3100

int cowMat[maxn][maxn];
queue<int> comfortableCows;
bool exist[maxn][maxn];
bool addExist[maxn][maxn];
int needed = 0;
int comfortable = 0;
int n;

void setIO(string name, bool includeout=false) { // name is nonempty for USACO file I/O
    ios_base::sync_with_stdio(0); cin.tie(0); // see Fast Input & Output
    // alternatively, cin.tie(0)->sync_with_stdio(0);
    freopen((name+".in").c_str(), "r", stdin); // see Input & Output
    if (includeout) {
        freopen((name+".out").c_str(), "w", stdout);
    }
}

bool isCowHere(int x, int y) {
    return exist[x][y];
}

void remove(int x, int y) {
    exist[x][y] = false;
    needed--;
}

void addToQueue(int x, int y){
    comfortableCows.push(3100 * x + y);
}

bool isComfortable(int x, int y) {
    if (cowMat[x][y] == 3) {
        return true;
    } 
    return false;
}

void updateNeighbors(int x, int y) {
    cowMat[x][y]++; 

    if (exist[x][y]) {
        if (cowMat[x][y] == 3) {  // i.e. this is comfortable now so increase the count
            comfortable++;
            addToQueue(x, y);
        } else if (cowMat[x][y] > 3) {  // i.e. it was comfortable before but now 4 neighbours so reduce the count
            comfortable--;
        }
    }
}

void add(int x, int y, string w) {
    exist[x][y] = true;
    if (cowMat[x][y] == 3) {
        comfortable++;
        addToQueue(x,y);
    }
    updateNeighbors(x-1, y);
    updateNeighbors(x+1, y);
    updateNeighbors(x, y-1);
    updateNeighbors(x, y+1);
}

void addAdditional(int x, int y) {
    addExist[x][y] = true;
    needed++;
}

void removeAdditionalCow(int x, int y) {
    addExist[x][y] = false;
    needed--;
}

bool isAdditionalCowHere(int x, int y) {
    return addExist[x][y];
}

int getFreeLoc(int x, int y) {
    if (!exist[x-1][y]) {
        return 3100*(x-1) + y;
    }
    if (!exist[x+1][y]) {
        return 3100*(x+1) + y;
    }
    if (!exist[x][y-1]) {
        return 3100*(x) + y-1;
    }
    if (!exist[x][y+1]) {
        return 3100*(x) + y+1;
    }
    throw invalid_argument("getFreeLocation called for non-comfortable cow:");
}

void update(){
    while(!comfortableCows.empty()) {
        int cow = comfortableCows.front();
        comfortableCows.pop();
        int x = cow / 3100;
        int y = cow % 3100;

        if (!isComfortable(x,y)) {
            continue;
        }

        int freePos = getFreeLoc(x,y);
        int freeX = freePos / 3100;
        int freeY = freePos % 3100;

        addAdditional(freeX, freeY);
        add(freeX, freeY, "additional");
    }
}

int main(){
    //setIO("1");
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        x += 1010;
        y += 1010;
        if(isCowHere(x,y)) {
            removeAdditionalCow(x,y);
        } else {
            add(x, y, "orig");
            update();
        }
        cout << needed << endl;
    }
    return 0;
}