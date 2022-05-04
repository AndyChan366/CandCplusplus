#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<algorithm>
typedef long long ll;
using namespace std;
int a[10007];    
int n,m,ans,x,y;
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d %d",&x,&y);
        a[x]++; a[y]++;
    }
    for(int i=1;i<=n;i++)
        if(a[i]%2==1) ans++;
    if(ans!=0) cout<<ans/2;
    else cout<<ans+1;
    return 0;
}
