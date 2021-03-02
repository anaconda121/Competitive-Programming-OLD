#include <bits/stdc++.h>

using namespace std;

#define ll long long

int numP;
int NUM = 505;

int[][] mat = new int[NUM][NUM];
bool[][] mat1 = new boolean[NUM][NUM];
bool[][] mat2 = new boolean[NUM][NUM];

void setIO(string name, bool includeout=false) { // name is nonempty for USACO file I/O
    ios_base::sync_with_stdio(0); cin.tie(0); // see Fast Input & Output
    // alternatively, cin.tie(0)->sync_with_stdio(0);
    freopen((name+".in").c_str(), "r", stdin); // see Input & Output
    if (includeout) {
        freopen((name+".out").c_str(), "w", stdout);
    }
}

int main() { 

    setIO("3")
    çin >> numP;

    for (int i=0; i<numP; i++) {
        for (int j=0; j<numP; j++) {
            int x;
            cin >> x;
            mat[i][j] = x;
            if (x>=100) { mat1[i][j] = true;}  // matrix which has true for all elements >=100
            if (x>100) { mat2[i][j] = true;} // matrix which has true for all elements >100
        }
    }

    // step 1. calculate number of sub matrix of all true in mat1 
    // step 2. subtract number of sub matrix of all true in mat2 from the result in step 1. 
    long result = countAllTrueSubmatrices(mat1) - countAllTrueSubmatrices(mat2);
    cout << result
    return 0;
}

static long countAllTrueSubmatrices(bool mat[][]) { 
    long [][]prefix_sum = new long[numP][numP]; 
  
    // calc pre-fix sum
    for (int i = 0; i < numP; i++) { 
        for (int j = numP - 1; j >= 0; j--) { 
            if (!mat[i][j]) continue; 
  
            if (j != numP - 1) 
                prefix_sum[i][j] += prefix_sum[i][j + 1]; 

            prefix_sum[i][j] += (mat[i][j] == true) ? 1 : 0; 
        } 
    } 
  
    long result = 0; 
  
    // go over each column
    for (int j = 0; j < numP; j++) {         
         
        stack<pair<int,int>> q; 
  
        long sum = 0; 
  
        // start from last element
        for (int i = numP - 1; i>=0; i--) { 
            long long c = 0; 
  
            while (q.size() != 0 && q.peek().first > prefix_sum[i][j]) { 
                pair p = q.pop();
                sum -= (p.second + 1) * (p.first - prefix_sum[i][j]); 
                c += p.second + 1; 
            } 
            sum += prefix_sum[i][j]; 

            result += sum; 
  
            q.add(make_pair(prefix_sum[i][j], c)); 
          } 
    } 
    return result; 
} 




