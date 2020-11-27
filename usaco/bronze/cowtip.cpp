#include <iostream>
#include <stdio.h>
using namespace std;
const int MAXN = 12;
int n,ans;
bool ar[MAXN][MAXN];
void flip(int a,int b){
    for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++){
            ar[i][j]=!ar[i][j];
        }
    }
}
int main(){
    freopen("cowtip.in","r",stdin);
    freopen("cowtip.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            char op;cin>>op;
            if(op=='1'){
                ar[i][j]=1;
            }
        }
    }
    for(int i=n;i>=1;i--){
        for(int j=n;j>=1;j--){
            if(ar[i][j]==1){
                flip(i,j);
                ans++;
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}