//http://www.usaco.org/index.php?page=viewproblem2&cpid=691

#include <algorithm>
#include <vector>
#include <math.h>
#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

int n;
vector<char> fjmoves;

void setIO(string name, bool includeout=false) { // name is nonempty for USACO file I/O
    ios_base::sync_with_stdio(0); cin.tie(0); // see Fast Input & Output
    // alternatively, cin.tie(0)->sync_with_stdio(0);
    freopen((name+".in").c_str(), "r", stdin); // see Input & Output
    if (includeout) {
        freopen((name+".out").c_str(), "w", stdout);
    }
}

int firstPlayerScore (char first, char second) {
    if (first == 'H' && second == 'S') return 1;
    if (first == 'P' && second == 'H') return 1;
    if (first == 'S' && second == 'P') return 1;
    return 0; 
}

int maxScore(char first, char second) {
    vector<int> results (n);
    int mScore = 0;
    //calculating scores assuming bessie switches as early as possible
    for (int i = 0; i < n; i++) {
        results[i] = firstPlayerScore(second, fjmoves[i]);
        mScore += results[i];
    }
    //calculating score assuming bessie switches from move 1 - move n-1
    int score = mScore;
    for (int i = 0; i < n; i++) {
        int temp = results[i];
        results[i] = firstPlayerScore(first, fjmoves[i]); //when i = 0, that means that bessie switched at move i=1
        score = score - temp + results[i];
        mScore = max(mScore, score);
    }
    return mScore;
}

/* LOGIC
    1. create a function that takes in 2 chars that represents 1 move / player and determine winner based on text
    2. use that function to calculate winner assuming bessie switches at move 0 - bessie switches at move n-1
    3. run that function for all possible combos (only 6 so this is feasible)
*/

int main() {
    setIO("hps", true);
    cin >> n;
    for (int i = 0; i < n; i++) {
        char a;
        cin >> a;
        fjmoves.push_back(a);
    }

    int mScore = maxScore('H', 'S');
    mScore = max(mScore, maxScore('H', 'P'));
    mScore = max(mScore, maxScore('P', 'H'));
    mScore = max(mScore, maxScore('P', 'S'));
    mScore = max(mScore, maxScore('S', 'H'));
    mScore = max(mScore, maxScore('S', 'P'));
    cout << mScore << endl;
    return 0;
}