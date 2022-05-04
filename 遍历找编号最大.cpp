#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
const int N = 10001;
int n,m,l;
int first[N];
bool visited[N];
struct node{
    int x,z,next;
}a[N];
void csh(int x, int z){
    a[++l].x=x;
    a[l].z=z;
    a[l].next=first[x];
    first[x]=l;
}

int dfs(int x, int y){
    visited[x]=1;
    if(x>y)y=x;
    for(int i=first[x];i;i=a[i].next){
        int z=a[i].z;
        if(visited[z])continue;
        y=max(y,dfs(z, y));
    }
    return y;
}
int main(){
    cin>>n>>m;
    l=0;
    memset(first, 0, sizeof(first));
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        csh(x,y);
    }
    for(int i=1;i<=n;i++){
        memset(visited,false,sizeof(visited));
        cout<<dfs(i, i)<<" ";
    }
    return 0;
}
