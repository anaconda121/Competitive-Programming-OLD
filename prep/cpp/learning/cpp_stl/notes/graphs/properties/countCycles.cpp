#include <bits/stdc++.h>

using namespace std;

#define MAXN 1005 //arbitrary #

/* logic

The "stack" contains nodes that can reach the current node. 

If the current node points to a node v on the stack (on_stack[v] is true), 
then we know that a cycle has been created. 

However, if the current node points to a node v that has been previously visited but is not on the stack, 
then we know that the current chain of nodes points into a cycle that has already been considered

*/

//Each node points to next_node[node]
bool visited[MAXN], on_stack[MAXN];
int number_of_cycles = 0, next_node[MAXN];

void dfs(int n) {
	visited[n] = on_stack[n] = true;
	int u = next_node[n];
	if(on_stack[u]) {
		number_of_cycles++;
    } else if(!visited[u]) {
		dfs(u);
    }
	on_stack[n] = false;
}

int main() {
	for (int i = 1; i <= N; i++) {
        int a;
        cin >> a;
        next_node[i] = a;
    }
	for (int i = 1;i <= N;i++) {
		if(!visited[i]) {
			dfs(i);
        }
    }
    return 0;
}
