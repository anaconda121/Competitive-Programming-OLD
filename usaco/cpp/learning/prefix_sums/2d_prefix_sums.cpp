/* matrix m 
    [1 5 6 11 8
    1 7 11 9 4
    4 6 1 3 2
    7 5 4 2 3]

Lets say we want to find sum of [7 11 9] and [6,1,3] in m.
What we can do is get the prefix sums of each row

m is now: 
[1 6 12 23 31
1 8 19 28 32
4 10 11 14 16
7 12 16 18 21]

apply what we used for 1-d prefix sums from specific non-zero indexes
sum of [7,11,9] = 28 - 1 = 27
sum of [6,1,3] = 14 - 4 = 10
add them up to get 37
but this is slow  --> O(QN)

** 2-d prefix sums **
do another prefix ontop of m, this time by col though:

m is now:
[1	6	12	23	31
2	14	31	51	63
6	24	42	65	79
13	36	58	83	100]
13 = 1+1+4+7
36 = 12+10+8+6 etc...

The submatrix sum between rows a and A and columns b$ and $B, can thus be expressed as follows:
sum = prefix[A][B] − prefix[a−1][B] − prefix[A][b−1] + prefix[a−1][b−1]
​this wld be 65 - 23 - 6 + 1 = 37

Prefix sum of an index = prefix[i][j]= prefix[i−1][j]+prefix[i][j−1] −prefix[i−1][j−1]+arr[i][j]
​	

this is O(NM) preprocessing, followed by O(1) finding time
*/

#include <algorithm>
#include <vector>
#include <math.h>
#include <iostream>
#include <stdio.h>

using namespace std;
using ll = long long;
using vl = vector<ll>;

int rows = 5;
int cols = 6;

int sumOfSubMatrix(int r, int col, int r2, int col2, int matrix[5][6]) {
    int sum = matrix[r2][col2] - matrix[r-1][col2] - matrix[r2][col-1] + matrix[r-1][col-1];
    //cout << matrix[r2][col2] << " , " << matrix[r-1][col2] << " , " << matrix[r2][col-1] << " , " << matrix[r-1][col-1] << endl;
    return sum;
}

int main() {
    int matrix[5][6]= {{0,0,0,0,0,0},{0,1,5,6,11,8}, {0,1,7,11,9,4}, {0,4,6,1,3,2}, {0,7,5,4,2,3}};
    int prefix[5][6] = {{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0}};
    //getting rows and cols of a matrix
    //cout << matrix.size() << endl; --> rows
    //cout << matrix[1].size() << endl; --> cols
    for (int i = 1; i < 5; i++) {
        for (int j = 1; j < 6; j++) {
            prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1] + matrix[i][j];
        }
    }
    
    /*PRINTING THE MATRIX*/
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 6; j++) {
            cout << prefix[i][j] << " ";
        }
        cout << "\n";
    }
    cout << sumOfSubMatrix(2,2,3,4,prefix);
    return 0;
}