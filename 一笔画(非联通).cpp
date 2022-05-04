#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
int n,m;
int fd[10001];
int degree[10001];
int visited[10001];
int count[10001];
vector<int> v;
int f(int x){
    int r=x;
    while(fd[x]!=x){
        x=fd[x];
    }
    fd[r]=x;
    return x;
}
void Union(int a,int b){
    a=f(a);
    b=f(b);
    if(a!=b){
        fd[b]=a;
    }
}
int main(){
        int ans;
        cin>>n>>m;
        for(int i=1; i<=n; i++){
            fd[i]=i;
            degree[i]=0;
            visited[i]=0;
            count[i]=0;
        }
        for(int i=0; i<m; i++){
            int a,b;
            cin>>a>>b;
            degree[a]++;
            degree[b]++;
            Union(a,b);
        }
        for(int i=1; i<=n; i++){
            fd[i]=f(i);
            if(visited[fd[i]]==0){
                v.push_back(fd[i]);
                visited[fd[i]]=1;
            }
            if(degree[i]%2)
                count[fd[i]]++;
        }
        for(int i=0;i<v.size();i++){
            int z=v[i];
            if(degree[z]==0)continue;
            if(count[z]==0)ans=ans+1;
            else ans=ans+count[z]/2;
        }
        cout<<ans;
    return 0;
}

