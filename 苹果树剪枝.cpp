#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
int b[3001][3001]; 
int c[101],flag;
struct edge {
	int next,to,w;
} a[3001];
void add(int x,int y,int w){
	a[++flag]=edge {c[x],y,w};
	c[x]=flag;
}
int dfs(int x,int t){
	int sum=0;
	for(int i=c[x];i!=0;i=a[i].next){
		if(a[i].to==t)continue; 
		sum+=dfs(a[i].to,x)+1;
		for(int j=sum;j>=1;j--){
			for(int k=1;k<=j;k++){
				b[x][j]=max(b[x][j],b[x][j-k]+b[a[i].to][k-1]+a[i].w);
            }
        }
	}
	return sum;
}
int main(){
	int n,m,x,y,z;
	cin>>n>>m;
	for(int i=1;i<n;i++){
		cin>>x>>y>>z;
		add(x,y,z);
		add(y,x,z);
	}
	dfs(1,0);
	cout<<b[1][m]; 
}
