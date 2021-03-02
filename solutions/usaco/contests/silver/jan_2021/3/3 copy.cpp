#include <algorithm>
#include <vector>
#include <math.h>
#include <iostream>

using namespace std;

#define maxn 1000

int n;
int beauty[maxn+2][maxn+2];    
int bclone[maxn+2][maxn+2];

void setIO(string name, bool includeout=false) { // name is nonempty for USACO file I/O
    ios_base::sync_with_stdio(0); cin.tie(0); // see Fast Input & Output
    // alternatively, cin.tie(0)->sync_with_stdio(0);
    freopen((name+".in").c_str(), "r", stdin); // see Input & Output
    if (includeout) {
        freopen((name+".out").c_str(), "w", stdout);
    }
}

void checkCondition(int i, int j) {
    int b0 = bclone[i][j];
    int b1 = bclone[i][j+1];
    int b2 = bclone[i+1][j];
    int b3 = bclone[i+1][j+1];

    if (b0 >= b1 && b0 >=b3) {
        if (b2 >= b1 && b2 >= b3) {
            // b0 and b2 will stay
            bclone[i][j+1] = -1; // b1
            bclone[i+1][j+1] = -1; // b3
        } else if (b1 >= b3) {
            //b0 and b1 will stay
            bclone[i+1][j] = -1;
            bclone[i+1][j+1] = -1;
        } else {
            // b0 and b3 stay
            bclone[i][j+1] = -1;
            bclone[i+1][j] = -1;
        }
    } else {
        // b0 is going
        bclone[i][j] = -1;

        if (b2>=b1) {
            if (b1>=b3) {
                // b2 and b1 stay
                bclone[i+1][j+1] = -1; 
            } else {
            // b2 and b3 stay
                bclone[i][j+1] = -1;
            }
        }
    }
}


void checkConditionReverse(int i, int j) {
    int b3 = bclone[i][j];
    int b2 = bclone[i][j+1];
    int b1 = bclone[i+1][j];
    int b0 = bclone[i+1][j+1];

    if (b0 >= b1 && b0 >=b3) {
        if (b2 >= b1 && b2 >= b3) {
            // b0 and b2 will stay
            bclone[i][j] = bclone[i+1][j] = -1;

        } else if (b1 >= b3) {
            //b0 and b1 will stay
            bclone[i][j] = bclone[i][j+1] = -1;
        } else {
            // b0 and b3 stay
            bclone[i+1][j] = bclone[i][j+1] = -1;
        }
    } else {
        // b0 is going
        bclone[i+1][j+1] = -1;

        if (b2>=b1) {
            if (b1>=b3) {
                // b2 and b1 stay
                bclone[i][j] = bclone[i+1][j+1] = -1;
            } else {
            // b2 and b3 stay
                bclone[i+1][j+1] = bclone[i+1][j] = -1;
            }
        }
    }
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

int calcScore(int mat[maxn+2][maxn+2]) {
    int score = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (mat[i][j] != -1) score += mat[i][j];
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

    for (int i=0; i <=n+1; i++) {
        beauty[0][i] = beauty[i][0] = -1;
        bclone[0][i] = bclone[i][0] = -1;

        beauty[n+1][i] = beauty[i][n+1] = -1;
        bclone[n+1][i] = bclone[i][n+1] = -1;
    }
    //printMat(beauty, 0, n+1, "beauty");

    int maxscore=0;

    for (int k=0; k<n; k++) {
        
        for (int j = 1; j <= n; j++) {
            for (int i = 1; i <= n; i++) {
                checkCondition(i-1,j-1);
            }
        }

        maxscore = max(maxscore, calcScore(bclone));

        //printMat(bclone, 1, n, "bclone");

        for (int j = n-1; j >= 1; j--) {
            for (int i = n-1; i >= 1; i--) {

                bclone[i][j] = beauty[i][j];
                checkConditionReverse(i,j);

                //char s[50]; sprintf(s, "bclone %d %d", i, j);
                //printMat(bclone, 1, n, s);

            }
        }

        maxscore = max(maxscore, calcScore(bclone));
    }

    //printMat(bclone, 1, n, "bclone");

    cout << maxscore << endl;

    return 0;
}
