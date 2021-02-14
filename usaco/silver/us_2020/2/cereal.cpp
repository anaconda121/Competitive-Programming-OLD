//problem: http://www.usaco.org/index.php?page=viewproblem2&cpid=1039

/*
LOGIC
Simulating this cereal grabbing would be O(N^2), too slow
Instead, we can "simulate" the grabbing from the back in O(N) time

Sample Case:
Cow 4 will get cereal #1
Cow 3 first priority is #1, but since the normal simulation will start from Cow 1, Cow 4 will get kicked out
We now go to Cow 4's second priority is #2, Cow 4 will now get cereal #2
Cow 2's first priority is #1, so it will kick out Cow 3
Cow 3's second priority is #2, so it will Cow 4
Cow 1's first priority is #1, so it will kick out Cow 2
Cow 2's second priority is #2, so it will check out Cow 3

1 2 3 4
1 2 _ _

Loop over array, if val = 0, then set it to arr[i-1]
Print array out in reverse
*/

#include <bits/stdc++.h>

using namespace std;

#define maxn 100005
#define f first
#define s second

int n, m;
vector<pair<int,int>> priorities;
int cereal[maxn];
int sol[maxn];
int ans = 0;

void setIO(string name, bool includeout=false) { // name is nonempty for USACO file I/O
    ios_base::sync_with_stdio(0); cin.tie(0); // see Fast Input & Output
    // alternatively, cin.tie(0)->sync_with_stdio(0);
    freopen((name+".in").c_str(), "r", stdin); // see Input & Output
    if (includeout) {
        freopen((name+".out").c_str(), "w", stdout);
    }
}

int main(){
    setIO("cereal", true);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int a,b;
        cin >> a >> b; 
        priorities.push_back(make_pair(a,b));
    }
    for (int i = n-1; i >= 0; i--) {
        int currPos = priorities[i].f;
        int j = i;
        while (true) {
            if (cereal[currPos] == 0) {
                //empty space, add cow
                cereal[currPos] = j;
                ans++;
                break;
            } else if (cereal[currPos] < j) {
                //cereal[currPos] cow has greater priority, cannot be kicked
                break;
            } else {
                //kicking a cow out
                int n = cereal[currPos];
                cereal[currPos] = j;
                if (currPos == priorities[n].s) {
                    // n cow has nowhere to go, will moo in disappointment
                    break;
                }
                j = n;
                currPos = priorities[n].s;
            }
        }
        sol[i] = ans;
    }

    for (int i = 0; i < n; i++) {
        cout << sol[i] << "\n";
    }
    return 0;
}