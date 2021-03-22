#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vl = vector<ll>;
using vb = vector<bool>;
using pl = pair<ll, ll>;
using vpl = vector<pl>;
using vc = vector<char>;
using vs = vector<string>;
using str = string;

#define FastIO ios_base::sync_with_stdio(0); cin.tie(0)
#define pb push_back
#define mp make_pair
#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))
#define ins insert
#define f first
#define s second
#define sz(x) (ll)(x).size()
#define len(x) (ll)(x).length()
#define FOR(i, a, b) for(ll i=a; i<b; ++i)
#define ROF(i, b, a) for(ll i=(b)-1; i>=a; --i)
#define EACH(a, x) for(auto& a: x)

void setIO(string fileName = ""){
	FastIO;
	if(len(fileName)){
		freopen((fileName+".in").c_str(), "r", stdin);
		freopen((fileName+".out").c_str(), "w", stdout);
	}
}

char icecream[1001][1001];
bool visited[1001][1001];

ll n, perimeter, area;

bool cmp(pl a, pl b){
	if(a.f == b.f) return a.s > b.s;
	return a.f < b.f;
}

void DFS(ll i, ll j){
	if(i >= n || j >= n || i < 0 || j < 0 || visited[i][j] || icecream[i][j] == '.') return;
	visited[i][j] = true;
	if(icecream[i][j] == '#') area++;
	if(icecream[i-1][j] != '#') perimeter++;
	if(icecream[i+1][j] != '#') perimeter++;
	if(icecream[i][j-1] != '#') perimeter++;
	if(icecream[i][j-1] != '#') perimeter++;
	DFS(i-1, j); DFS(i+1, j); DFS(i, j-1); DFS(i, j+1);
}

int main(){
	setIO("perimeter");
	cin >> n;
	FOR(i, 0, n){
		FOR(j, 0, n){
			cin >> icecream[i][j];
		}
	}
	vpl properties;
	FOR(i, 0, n){
		FOR(j, 0, n){
			perimeter = 0, area = 0;
			DFS(i, j);
			if(perimeter && area) properties.pb(mp(area, perimeter));
		}
	}
	sort(all(properties), cmp);
	cout << properties[sz(properties)-1].f << " " << properties[sz(properties)-1].s << endl;
}