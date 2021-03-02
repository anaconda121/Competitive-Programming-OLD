#include <bits/stdc++.h>

using namespace std;

int cowN[1005][1005];
bool there[1005][1005];
int comfortable = 0;

void setIO(string name, bool includeout=false) { // name is nonempty for USACO file I/O
    ios_base::sync_with_stdio(0); cin.tie(0); // see Fast Input & Output
    // alternatively, cin.tie(0)->sync_with_stdio(0);
    freopen((name+".in").c_str(), "r", stdin); // see Input & Output
    if (includeout) {
        freopen((name+".out").c_str(), "w", stdout);
    }
}

void update(int x, int y){
    cowN[x][y]++;
    if (there[x][y]) {
        if (cowN[x][y]==3) {
            comfortable++;
        } else if (cowN[x][y] > 3) {
            comfortable--;
        }
    }
}

int main(){
    setIO("2");
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x,y;
        cin >> x >> y;
        x++; y++;
        there[x][y] = true;

        update(x+1,y);
        update(x-1,y);
        update(x, y+1);
        update(x, y-1);
        cout << comfortable << endl;
    }
    return 0;

}