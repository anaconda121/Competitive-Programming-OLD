//https://cses.fi/problemset/task/1192/
/* LOGIC

########
#..#...#
####.#.#
#..#...#
########

.. and whatever is in the those dots represent a room
so second row 2 dots are a room
so fourth row 2 dots are a room
so 3 dots on second row and 3 dots on fourth row with dots connecting those form a room, with one floor tile

therefore 3
*/

#include <bits/stdc++.h>

using namespace std;

#define MAXN 1005
#define MAXM 1005

char grid[MAXN][MAXM]; // the grid itself
int n, m; // grid dimensions, rows and columns
bool visited[MAXN][MAXM]; // keeps track of which nodes have been visited
int ans = 0; // reset to 0 each time we start a new component

void floodfill(int r, int c){
	if(r < 0 || r >= n || c < 0 || c >= m) return; // if outside grid
    if (grid[r][c] == '#') return;
	if(visited[r][c]) return; // already visited this square
	visited[r][c] = true; // mark current square as visited
	// recursively call floodfill for neighboring squares
	floodfill(r, c+1);
	floodfill(r, c-1);
	floodfill(r-1, c);
	floodfill(r+1, c);
}

int main(){
	cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char a;
            cin >> a;
            grid[i][j] = a;
        }
    }
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(!visited[i][j] && grid[i][j] == '.'){
				floodfill(i, j);
                ans++;
			}
		}
	}
    cout << ans << endl;
	return 0;
}