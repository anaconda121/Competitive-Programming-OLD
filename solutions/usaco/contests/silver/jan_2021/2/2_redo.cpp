#include <bits/stdc++.h>

using namespace std;

#define maxn 100005

/*LOGIC:
1. calc strokes need from 0 - a and from  n - b and sum those together for answer
2. scan the input from left to right while maintaining a stack of "active brush strokes". 
    Every time we see a higher color than the one on top of the stack, we push it onto the stack (so the stack will contain ascending colors from bottom to top). 
    Every time we see a color c, we pop from the stack every color larger than c, since those brush strokes need to be ended for color c to be visible. 
    The aggregate number of pushes onto the stack tells us the number of brush strokes required for each prefix.
3. need to reverse string for stroke calc from suffix count
*/

string fence;
int before[maxn], after[maxn];
int n, q;

void setIO(string name, bool includeout=false) { // name is nonempty for USACO file I/O
    ios_base::sync_with_stdio(0); cin.tie(0); // see Fast Input & Output
    // alternatively, cin.tie(0)->sync_with_stdio(0);
    freopen((name+".in").c_str(), "r", stdin); // see Input & Output
    if (includeout) {
        freopen((name+".out").c_str(), "w", stdout);
    }
}

void calcStrokes(int *arr) {
    stack<int> currStrokes;
    for (int i = 0; i < n; i++) {
        arr[i+1] = arr[i];
        while (!currStrokes.empty() && currStrokes.top() > fence[i]) {
            currStrokes.pop();
        }
        
        if (currStrokes.empty() || !currStrokes.empty() && currStrokes.top() < fence[i]) {
            currStrokes.push(fence[i]);
            arr[i+1]++;
        } 
    }
}

int main() {
    setIO("2");
    cin >> n >> q >> fence;
    calcStrokes(before);
    reverse(fence.begin(), fence.end());
    calcStrokes(after);

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        cout << before[a-1] + after[n-b] << endl;
    }
    return 0;
}