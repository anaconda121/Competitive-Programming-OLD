#include <bits/stdc++.h>

using namespace std;

#define MAXN 105 //abitrary
#define MAXM 105 //arbitrary

/*
Flood fill is an algorithm that identifies and labels the connected component that a particular cell belongs to in a multidimensional array.

For example, suppose that we want to split the following grid into components of connected cells with the same number. 

As opposed to an explicit graph where the edges are given, a grid is an implicit graph. 
This means that the neighbors are just the nodes directly adjacent in the four cardinal directions.
Usually, grids given in problems will be $N$ by $M$, so the first line of the input contains the numbers $N$ and $M$. 
In this example, we will use an two-dimensional integer array to store the grid, 
but depending on the problem, a two-dimensional character array or a two-dimensional boolean array may be more appropriate
Then, there are $N$ rows, each with $M$ numbers containing the contents of each square in the grid. 
*/

int grid[MAXN][MAXM]; // the grid itself
int n, m; // grid dimensions, rows and columns
bool visited[MAXN][MAXM]; // keeps track of which nodes have been visited
int currentSize = 0; // reset to 0 each time we start a new component

void floodfill(int r, int c, int color){
	if(r < 0 || r >= n || c < 0 || c >= m) return; // if outside grid
	if(grid[r][c] != color) return; // wrong color
	if(visited[r][c]) return; // already visited this square
	visited[r][c] = true; // mark current square as visited
	currentSize++; // increment the size for each square we visit
	// recursively call floodfill for neighboring squares
	floodfill(r, c+1, color);
	floodfill(r, c-1, color);
	floodfill(r-1, c, color);
	floodfill(r+1, c, color);
}

int main(){
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(!visited[i][j]){
				currentSize = 0;
				floodfill(i, j, grid[i][j]);
				// start a floodfill if the square hasn't
				// already been visited, and then
				// store or otherwise use the component size for whatever
				// it's needed for here
			}
		}
	}
	return 0;
}