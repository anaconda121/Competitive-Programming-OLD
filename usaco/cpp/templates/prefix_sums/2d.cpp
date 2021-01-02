#include <algorithm>
#include <vector>
#include <math.h>
#include <iostream>
#include <stdio.h>
#include <cstring>

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
    int prefix[5][6]; //= {{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0}};
    memset(prefix, sizeof(prefix)/sizeof(prefix[0]), 0);
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