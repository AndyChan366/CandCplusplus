#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=150001;
int f[maxn];
long long a[maxn+100];
int n,m;
int father(int x){
	if(x==f[x])	return x;
	else return f[x]=father(f[x]);
}
int main(){
	int x,y;
	while(scanf("%d%d",&n,&m)!=EOF){
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++){
            f[i]=i;
        }
		for(int i=1;i<=m;i++){
			cin>>x>>y;
			int fx=father(x);
			int fy=father(y);
			if(fx!=fy)f[fx]=fy;
		}
		for(int i=1;i<=n;i++){
            a[father(i)]++;
        }
		long long sum=0;
		for(int i=1;i<=n;i++){
			if(a[i]!=0&&a[i]!=1){
				sum+=(a[i]*(a[i]-1))/2;
			}
		}
		if(sum==m)cout<<"YES";
		else cout<<"NO";
	}
	return 0;
}