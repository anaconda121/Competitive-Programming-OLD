#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MAXN 100005 //arbitrary #

/* logic

The "stack" contains nodes that can reach the current node. 

If the current node points to a node v on the stack (on_stack[v] is true), 
then we know that a cycle has been created. 

However, if the current node points to a node v that has been previously visited but is not on the stack, 
then we know that the current chain of nodes points into a cycle that has already been considered

*/

//Each node points to next_node[node]

int N, status[MAXN], parent[MAXN];
ll ans = 0;

void setIO(string name, bool includeout=false) { // name is nonempty for USACO file I/O
    ios_base::sync_with_stdio(0); cin.tie(0); // see Fast Input & Output
    // alternatively, cin.tie(0)->sync_with_stdio(0);
    freopen((name+".in").c_str(), "r", stdin); // see Input & Output
    if (includeout) {
        freopen((name+".out").c_str(), "w", stdout);
    }
}

void count(int i) {
    bool there[MAXN];
    while (status[i] == 0) {
        there[i] = true;
        status[i] = 1;
        i = parent[i];
    }
    if (there[i]) {
        int save = i;
        do {
            status[i] = 2;
            i = parent[i];
        } while (i != save);
    }
}

int main() {
    setIO("shuffle", true);
    cin >> N;
	for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        a--;
        parent[i] = a;
    }
	for (int i = 0;i < N;i++) {
		if (status[i] == 0) {
			count(i);
        }
    }
    for (int i = 0; i < N; i++) {
        if (status[i] == 2) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
 