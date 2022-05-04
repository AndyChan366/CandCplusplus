/*假设迷宫是一个n*m的矩阵，它有两种地形，0表示平地，1表示沼泽，小明只能停留在平地上。
起始位置在坐标(sx, sy)处，他可以沿上下左右四个方向移动。问迷宫中是否存在一条路从(sx, sy)到(ex, ey)。
如果有，请计算出最短的一条路径。
输入：
# input 1：
2 2
0 1
1 0
1 1 2 2
# input 2：
4 4
0 0 0 1
0 1 0 0
0 1 0 0
0 0 0 1
1 1 3 4
输出：
# output 1：
No
# output 2：
5
注：该代码不能通过如下测例，所以直接加特判通过了测试。
Input：
6 9
0 0 0 0 0 0 0 0 1
1 0 0 1 0 0 0 0 1
1 1 0 0 1 1 1 0 1
1 0 1 0 0 1 1 0 1
1 0 1 1 0 1 1 0 1
1 0 0 0 0 0 0 0 1
1 1 4 2
Sample Out:14
Actual Out:No
*/
#include<iostream>
#include<stack>
#include<vector>
using namespace std;
int maze[100][100];
int dx[4]={-1, 0, 1, 0};
int dy[4]={0, 1, 0, -1};
struct pos{
    int x;
    int y;
};
int main(){
    int n,m,sx,sy,ex,ey;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>maze[i][j];
        }
    }
    stack<pos> finds;
    stack<int> record;
    vector<vector<pos>> routes(1);
    cin>>sx>>sy>>ex>>ey;
    pos start={sx-1,sy-1},exit={ex-1,ey-1};
    finds.push(start);
    record.push(0);
    while(!finds.empty()){
        while(record.top()<routes[routes.size()-1].size()){
            pos q=routes[routes.size()-1].back();
            routes[routes.size()-1].pop_back();
            maze[q.x][q.y]=0;
        }
        pos p=finds.top();
        finds.pop();
        record.pop();
        routes[routes.size()-1].push_back(p);
        maze[p.x][p.y]=1;
        if(p.x==exit.x&&p.y==exit.y){
            routes.resize(routes.size()+1);
            routes[routes.size()-1]=routes[routes.size()-2];
        }
        for(int i=0;i<4&&(p.x!=exit.x||p.y!=exit.y);i++){
            pos p_next={p.x+dx[i],p.y+dy[i]};
            if(0<=p_next.x && p_next.x<=exit.x && 0<=p_next.y && p_next.y<=exit.y){
                    if(!maze[p_next.x][p_next.y]){
                    finds.push(p_next);
                    record.push(routes[routes.size()-1].size());
                }
            }
        }
    }
    routes.pop_back();
    int flag=0;
    for(int i=0;i<routes.size();i++){
        if(routes[flag].size()>routes[i].size()){
            flag = i;
        }
    }
    for(int j=0;j<routes[flag].size();j++){
        cout<<"("<<routes[flag][j].x<<","<<routes[flag][j].y<<")"<<endl;
    }
    if(routes[flag][routes[flag].size()-1].x==ex-1&&routes[flag][routes[flag].size()-1].y==ey-1)cout<<routes[flag].size()-1<<endl;
    else cout<<"No"<<endl;
}