#include <iostream>
#include <set>
#include <algorithm>
#include <math.h>

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
using namespace std;
using ll=long long;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n,x;
  cin>>x>>n;
  multiset<ll> a,b;
  a.insert(0);
  a.insert(x);
  b.insert(x);
  forn(i,n){
    ll k;
    cin>>k;
    auto it=a.upper_bound(k);
    auto it1=it;
    it1--;
    ll diff=*it-*it1;
    b.erase(b.find(diff));
    a.insert(k);
    b.insert(*it-k);
    b.insert(k-*it1);
    cout<<(*b.rbegin())<<" ";
  }  
  return 0;
} 