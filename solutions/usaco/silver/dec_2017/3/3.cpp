#include <bits/stdc++.h>

using namespace std;

#define MAXN 100005 //arbitrary #

/* logic

The "stack" contains nodes that can reach the current node. 

If the current node points to a node v on the stack (on_stack[v] is true), 
then we know that a cycle has been created. 

However, if the current node points to a node v that has been previously visited but is not on the stack, 
then we know that the current chain of nodes points into a cycle that has already been considered

*/

//Each node points to next_node[node]

bool visited[MAXN], contains[MAXN];
long long number_of_cycles = 0;
int next_node[MAXN], status[MAXN], N;

void setIO(string name, bool includeout=false) { // name is nonempty for USACO file I/O
    ios_base::sync_with_stdio(0); cin.tie(0); // see Fast Input & Output
    // alternatively, cin.tie(0)->sync_with_stdio(0);
    freopen((name+".in").c_str(), "r", stdin); // see Input & Output
    if (includeout) {
        freopen((name+".out").c_str(), "w", stdout);
    }
}

void countCycles(int i) {

    vector<int> there;

    while (status[i] == 0) {
        there.push_back(i);
        i = next_node[i];
        status[i] = 1;
    }

    if (count(there.begin(), there.end(), i)) {
        int save = i;
        do {
            status[i] = 2;
            i = next_node[i];
        } while (i != save);
    }
}

int main() {
    setIO("shuffle");
    cin >> N;
	for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        a--;
        next_node[i] = a;
    }
	for (int i = 0;i < N;i++) {
		if (!visited[i]) {
			countCycles(i);
        }
    }
    for (int i = 0; i < N; i++) {
        if (status[i] == 2) {
            number_of_cycles++;
        }
    }
    cout << number_of_cycles << endl;
    return 0;
}
 