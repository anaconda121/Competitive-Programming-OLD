//https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=1384
//the brutest of brute force

#include <bits/stdc++.h>

using namespace std;

int moves[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

void setIO(string name = "", bool includeout = false) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((name+".in").c_str(), "r", stdin);
    if (includeout)
        freopen((name+".out").c_str(), "w", stdout);
}

bool check(char a, char b) {
    if(a == 'R'){
		if(b == 'S') {
			return true;
        }
        return false;
	}
	if(a == 'P'){
		if(b == 'R') {
			return true;
        }
        return false;
	}
	if(a == 'S' && b == 'P') {
	    return true;
    }
    return false;
}

int main() {
    //setIO("rps");
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int r, c, n;
        cin >> r >> c >> n;
        vector< vector<char> > mat(r, vector<char>(c));
        for (int e = 0; e < r; e++) {
            for (int j = 0; j < c; j++) {
                char c;
                cin >> c;
                mat[e][j] = c;
            }
        }
        for (int k = 0; k < n; k++) {
            vector< vector<char> > changes(mat);
            for (int y = 0; y < r; y++) {
                for (int z = 0; z < c; z++) {
                    for(int f = 0; f < 4; f++){
						int x = y + moves[f][0];
						int y2 = z + moves[f][1];
						if(x > -1 && x < r && y2 > -1 && y2 < c){
							if(check(changes[y][z], changes[x][y2]))
								mat[x][y2] = changes[y][z];
						}
					}
                }
            }
        }
        for (int a = 0; a < r; a++) {
            for (int b = 0; b < c; b++) {
                cout << mat[a][b];
            }
            cout << endl;
        }
        if (i < t-1) {
            cout << endl;
        }
    }
    return 0;
}
