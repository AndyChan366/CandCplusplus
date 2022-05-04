#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
const int N=200001;
int depth[N],par[N],a[N],vis[N],n,total;
struct Edge{
	int v,x;
}e[N<<1];
void add(int u,int v){
	e[total].v=v;
	e[total].x=a[u];
	a[u]=total++;
}
void dfs(int u,int f){
	for(int i=a[u];~i;i=e[i].x){
		int v=e[i].v;
		if(v==f)continue;
		par[v]=u;
        depth[v]=depth[u]+1;
		dfs(v,u);
	}
}
int main(){
    priority_queue<pair<int,int>>q;
	memset(a,-1,sizeof(a));
	cin>>n;
	int u,v,ans=0;
	for(int i=1;i<n;i++){
		cin>>u>>v;
		add(u,v);
        add(v,u);
	}
	dfs(1,0);
	for(int i=1;i<=n;i++){
        if(depth[i]>2)q.push(make_pair(depth[i],i));
    }
	while(q.size()){
		u=q.top().second;
        q.pop();
		if(vis[u])continue;
		ans++;
        vis[par[u]]=1;
		for(int i=a[par[u]];~i;i=e[i].x){
            vis[e[i].v]=1;
        }
	}
	cout<<ans<<endl;
	return 0;
}
