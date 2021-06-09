//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3399
//literally just brute force
//for every single possible value that could work as the minimum, check all possible permutations to see if any work
// if any do, that does is that answer, otherwise -1

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

bool check(int A[], int B[]) {
    sort(A, A + 3);
    bool dubs = true;
    do {
        sort(B, B + 3);
        do {
            int C = 0;
            for (int j = 0; j < 3; j++) {
                if (A[j] < B[j]) C++;
            }
            if (C < 2) dubs = false;
        } while (next_permutation(B, B + 3));
    } while (next_permutation(A, A + 3) );

    return dubs;
}

int main() {
    //setIO("jollo");
    while (true) {
        int X[3], Y[3], i;
        cin >> X[0] >> X[1] >> X[2] >> Y[0] >> Y[1];
        if (X[0] == 0 && X[1] == 0 && X[2] == 0 && Y[0]== 0 && Y[1] == 0) break;
        set<int> cards;
        cards.insert(X[0]); cards.insert(X[1]); cards.insert(X[2]);
        cards.insert(Y[0]); cards.insert(Y[1]);
        bool dubs = false;
        for (int i = 1; i < 53; i++) {
            if (cards.find(i) != cards.end()) continue;
            Y[2] = i;
            int A[3], B[3];
            for (int i = 0; i < 3; i++) {
                A[i] = X[i];
                B[i] = Y[i];
            }
            if (check(A,B)){
                dubs = true;
                break;
            }
        }
        if (dubs){
            cout << Y[2] << endl;
        } else {
            cout << "-1" << endl;
        }
    }
    return 0;
}

