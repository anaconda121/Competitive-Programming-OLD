//https://www.youtube.com/watch?v=FwtF55Cwt3s&ab_channel=HJKZ
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define f first
#define s second

int n, k;
int main() {
    cin >> n >> k;
    vector<int> stacks (n+1);
    // for (int i = 0; i < n+5; i++) {
    //     stacks[i]=0;
    // }
    for (int i = 0; i < k; i++) {
        int a,b;
        cin >> a >> b;
        //a--; b--;
        stacks[a]++;
        stacks[b+1]--;
        // for (int i = 0; i <= stacks.size() ;i++){
        //     cout << stacks[i] << " , ";
        // }
        // cout << endl;
    }
    for (int i = 1; i <= n; i++) {
        stacks[i] += stacks[i-1];
    }

    sort(stacks.begin(), stacks.end());
    for (int i = 0; i <= stacks.size() ;i++){
        cout << stacks[i] << " , ";
    }
    cout << endl;
    cout << stacks[n/2+1] << endl;
    return 0;
}
