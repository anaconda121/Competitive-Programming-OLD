#include <bits/stdc++.h>

using namespace std;

#define maxn 5000
#define ll long long
#define pb push_back
#define f first
#define s second

bool there[maxn][maxn];
queue<pair<int,int>> add;
int n;
int xAdd[4] = {1,-1,0,0};
int yAdd[4] = {0,0,1,-1};
ll total = 0;

void setIO(string name, bool includeout=false) { // name is nonempty for USACO file I/O
    ios_base::sync_with_stdio(0); cin.tie(0); // see Fast Input & Output
    // alternatively, cin.tie(0)->sync_with_stdio(0);
    freopen((name+".in").c_str(), "r", stdin); // see Input & Output
    if (includeout) {
        freopen((name+".out").c_str(), "w", stdout);
    }
}

void eval(int x, int y) {
    if (!there[x][y]) return;
    int adj = 0;
    for (int i = 0; i < 4; i++) {
        adj += there[x + xAdd[i]][y + yAdd[i]];
    }
    //cout << adj << " " << x << " , " << y << endl;
    if (adj == 3) {
        //cout << "3!\n";
        for (int i = 0; i < 4; i++) {
            pair<int,int> next {x + xAdd[i], y + yAdd[i]};
            if (!there[next.f][next.s]) {
                //cout << "pushing\n";
                //next.f , next.s is coords for 4th dood
                add.push({next.f, next.s});
            }
        }
    }
}

int main(){
    //setIO("1");
    cin >> n;
    for (int i = 1; i <= n; i++) {
        pair<int,int> coord;
        cin >> coord.f >> coord.s;
        coord.f += 1500;
        coord.s += 1500;
        add.push(coord);
        while (!add.empty()){
            //cout << "entering\n";
            pair<int,int> curr = add.front();
            add.pop();
            if (there[curr.f][curr.s]) continue;
            there[curr.f][curr.s] = true;
            total++;
            //cout << total << endl;
            eval(curr.f, curr.s);
            for (int i = 0; i < 4; i++) {
                eval(curr.f + xAdd[i], curr.s + yAdd[i]);
            }
        }
        cout << total - i << endl;
    }
    return 0;
}