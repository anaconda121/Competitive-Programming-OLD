#include <algorithm>
#include <vector>
#include <math.h>
#include <iostream>

using namespace std;

#define maxn 1000

int n;
int beauty[maxn+2][maxn+2];    
int bclone[maxn+2][maxn+2];
int filled[maxn+2][maxn+2];

void setIO(string name, bool includeout=false) { // name is nonempty for USACO file I/O
    ios_base::sync_with_stdio(0); cin.tie(0); // see Fast Input & Output
    // alternatively, cin.tie(0)->sync_with_stdio(0);
    freopen((name+".in").c_str(), "r", stdin); // see Input & Output
    if (includeout) {
        freopen((name+".out").c_str(), "w", stdout);
    }
}

bool check2x2square(int i, int j) {
    int b0 = filled[i][j];
    int b1 = filled[i][j+1];
    int b2 = filled[i+1][j];
    int b3 = filled[i+1][j+1];

    return (b0+b1+b2+b3)==2;
}

bool checkmat() {
    for (int i=1; i<n; i++)
        for (int j=1; j<n; j++) {
            if (!check2x2square(i,j)) return false;
        }
    return true;
}


void printMat(int mat[maxn+2][maxn+2], int st, int en, string name) {
    cout << name << endl;
    for (int  i=st; i<=en; i++) {
        for (int  j=st; j<=en; j++)  {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}
 
int calcScore() {
    int score = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            score += filled[i][j] * beauty[i][j];
        }
    }
    return score;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); 

    //setIO("3");

    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int a;
            cin >> a;
            beauty[i][j] = a;
            bclone[i][j] = a;
        }
    }

    int maxcowsallowed = n * (n+1)/2;
    int maxscore=0;

    for (int s=0; s<pow(2, n*n); s++) {
        int ncows = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int flag = (s & (1 << i*n + j)) > 0;
                filled[i+1][j+1] = flag;
                ncows += flag; 
            }  
        }
        if (ncows <= maxcowsallowed && checkmat()) {
            int sc = calcScore();
            // if (sc==24) 
            //     printMat(filled, 1, n, "filled");

            maxscore = max(maxscore, sc);
        }
    }

    cout << maxscore << endl;

    return 0;
}
