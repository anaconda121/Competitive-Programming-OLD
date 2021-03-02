#include <iostream>
#include <fstream>
#include <string>
#include <set>
using namespace std;
 
int N;
string S;
 
bool dups(int len, set<string> X)
{
  for (int i=0; i<=N; i++) {
    if (X.count(S.substr(i,len)) > 0) return true;
    X.insert(S.substr(i,len));
  }
  return false;
}
 
int main(void)
{
  set<string> X;
  ifstream fin ("whereami.in");
  ofstream fout ("whereami.out");
  fin >> N >> S;
  int ans = 1;
  while (dups(ans,X)) ans++;
  fout << ans << "\n";
  return 0;
}