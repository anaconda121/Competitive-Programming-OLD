#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 100000
 
int N;
int x[MAXN], y[MAXN];
int pos[MAXN], neg[MAXN];
int cid[MAXN];
 
void setIO(string name = "") { // name is nonempty for USACO file I/O
    ios_base::sync_with_stdio(0); cin.tie(0); // see Fast Input & Output
    // alternatively, cin.tie(0)->sync_with_stdio(0);
    freopen((name+".in").c_str(), "r", stdin); // see Input & Output
    freopen((name+".out").c_str(), "w", stdout);
}

bool cmp(int a,int b)
{
	if(neg[a] == neg[b])
		return pos[a] > pos[b];
	return neg[a] < neg[b];
}
 
int main()
{
    setIO("mountains");
	cin >> N;
	for(int i=0;i<N;i++) {
		cin >> x[i] >> y[i];
		pos[i] = x[i]+y[i], neg[i] = x[i]-y[i];
		cid[i] = i;
	}
	sort(cid,cid+N,cmp);
    int mxpos = -1;
    int ans = 0;
	for(int i=0;i<N;i++)
	{
		if(pos[cid[i]] > mxpos)
		{
			ans++;
			mxpos = pos[cid[i]];
		}
	}
	cout << ans << '\n';
}