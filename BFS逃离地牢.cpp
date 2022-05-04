#include<iostream>
#include<cstring>
#include<string.h>
#include<queue>
using namespace std;
const int N=100;
int n,m,ans;
char zhouyu[N][N];
bool visited[N][N][N][N];
int dis[N][N];
char attract[N];
int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
int goah[4][2];
pair<int,int> start,ending;
struct node{
    int sx,sy,ex,ey,coun;
};
void bfs(){
    node s,temp;
    ans=-1;
    s.sx=start.first;
    s.sy=start.second;
    s.ex=ending.first;
    s.ey=ending.second;
    s.coun=0;
    queue<node> q;
    q.push(s);
    visited[s.sx][s.sy][s.ex][s.ey]=true;
    while(q.size()){
        s=q.front();
        temp.coun=s.coun+1;
        q.pop();
        if(temp.coun>255)return;
        for(int i=0;i<4;i++){
            temp.sx=s.sx+dir[i][0];
            temp.sy=s.sy+dir[i][1];
            if(zhouyu[temp.sx][temp.sy]=='#'||zhouyu[temp.sx][temp.sy]=='!')continue;
            int x=s.ex+goah[i][0];
            int y=s.ey+goah[i][1];
            if(zhouyu[x][y]=='!')continue;
            if(zhouyu[x][y]=='#'){
                x-=goah[i][0];
                y-=goah[i][1];
            }
            temp.ex=x;
            temp.ey=y;
            if(temp.sx==temp.ex&&temp.sy==temp.ey){
                ans=temp.coun;
                return;
            }
            if(temp.sx==s.ex&&temp.sy==s.ey&&temp.ex==s.sx&&temp.ey==s.sy){
                ans=temp.coun;
                return;
            }
            if(visited[temp.sx][temp.sy][temp.ex][temp.ey])continue;
            q.push(temp);
            visited[temp.sx][temp.sy][temp.ex][temp.ey]=true;
        }
    }
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        scanf("%s",zhouyu[i]+1);
        for(int j=1;j<=m;j++){
            if(zhouyu[i][j]=='P')start=pair<int,int> (i,j);
            else if(zhouyu[i][j]=='H')ending=pair<int,int> (i,j);
        }
    }
    cin>>attract;
    for(int i=0;i<4;i++){
        if(attract[i]=='W')goah[i][0]=0,goah[i][1]=-1;
        else if(attract[i]=='N')goah[i][0]=-1,goah[i][1]=0;
        else if(attract[i]=='S')goah[i][0]=1,goah[i][1]=0;
        else goah[i][0]=0,goah[i][1]=1;
    }
    bfs();
    if(ans!=-1)cout<<ans<<endl;
    else cout<<"Impossible"<<endl;
    return 0;
}
