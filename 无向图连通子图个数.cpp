#include<iostream>
#include<queue>
using namespace std;
int adj[101][101];
bool visited[101];
int main(){
    int m,n,start,last,coun,num,T;
    cin>>T;
    for(int i=0;i<T;i++){
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            visited[i]=false;
            for(int j=1;j<=n;j++){
                adj[i][j] = 0;
            }
        }
        for(int i=0;i<m;i++){
            cin>>start>>last;
            adj[start][last]=1;
            adj[last][start]=1;
        }
        queue<int> q;
        coun=n;
        num=0;
        while(coun>0){
            for(int i=1;i<=n;i++){
                if(!visited[i]){
                    q.push(i);
                    visited[i]=true;
                    coun--;
                    num++;
                    break;
                }
            }
            while(!q.empty()){
                int top=q.front();
                q.pop();
                for(int k=1;k<=n;k++){
                    if(!visited[k]&&adj[top][k]==1){
                        q.push(k);
                        visited[k]=true;
                        coun--;
                    }
                }
            }
        }
        if(num==1)cout<<"YES, "<<num<<" component."<<endl;
        else cout<<"NO, "<<num<<" components."<<endl;
    }
}   