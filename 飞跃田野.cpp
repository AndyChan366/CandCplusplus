/*题目描述：
勇敢的德鲁伊法里奥出色的完成了任务之后，正在迅速的向自己的基地撤退。但由于后面有着一大群追兵，所以法里奥要尽快地返回基地，否则就会被敌人捉住。
终于，法里奥来到了最后的一站：泰拉希尔原野，穿过这里就可以回到基地了。然而，敌人依然紧追不舍。
不过，泰拉希尔的地理条件对法里奥十分有利，众多的湖泊随处分布。敌人需要绕道而行，但法里奥拥有变成鹰的特殊能力，使得他能轻轻松松的飞越湖面。
当然，为了保证安全起见，法里奥还是决定找一条能最快回到基地的路。
假设泰拉希尔原野是一个m*n的矩阵，它有两种地形，P表示平地，L表示湖泊，法里奥只能停留在平地上。
他目前的位置在左上角(1,1)处，而目的地为右下角的(m,n)。法里奥可以向前后左右四个方向移动或者飞行，每移动一格需要1单位时间。
而飞行的时间主要花费在变形上，飞行本身时间消耗很短，所以无论一次飞行多远的距离，都只需要1单位时间。
飞行的途中不能变向，并且一次飞行最终必须要降落在平地上。当然，由于受到能量的限制，法里奥不能无限制的飞行，他总共最多可以飞行的距离为D。
在知道了以上的信息之后，请你帮助法里奥计算一下，他最快到达基地所需要的时间。
输入：
第一行是3个正整数，m(1≤m≤100)，n(1≤n≤100)，D(1≤D≤100)。表示原野m*n是的矩阵，法里奥最多只能飞行距离为D。
接下来的m行每行有n个字符。P表示当前位置是平地，L则表示湖泊。假定(1,1)和(m,n)一定是平地。
输出：
一个整数，表示法里奥到达基地需要的最短时间。如果无法到达基地，则输出impossible。
样例输入：
4 4 2
PLLP
PPLP
PPPP
PLLP
样例输出：
5
TIP：路径途径(2,1),(2,2),(2,4),(3,4),(4,4)。
*/
#include<iostream>
#include<algorithm>
#include<string.h>
#include<queue>
using namespace std;
char f[101][101];
bool visited[101][101][101];
struct node{
    int x,y,d,time;
};
int n,m,d;
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
void bfs(){
    queue<node>Q;
    node t;
    t.time=t.x=t.y=0,t.d=d;
    Q.push(t);
    while(!Q.empty()){
        node v=Q.front(); Q.pop();
        if(v.x==m-1 && v.y==n-1){
            cout<<v.time;
            return;
        }
        for(int i=0;i<4;i++){
            t.x=v.x+dir[i][0];
            t.y=v.y+dir[i][1];
            t.d=v.d;
            if(t.x<m && t.x>=0 && t.y<n && t.y>= 0 && !visited[t.x][t.y][t.d] && f[t.x][t.y]=='P'){
                visited[t.x][t.y][t.d]=1;
                t.time=v.time+1;
                Q.push(t);
            }
            for(int j=2;j<=v.d;j++){
                t.x=v.x+j*dir[i][0];
                t.y=v.y+j*dir[i][1];
                if(t.x<m && t.x>=0 && t.y<n && t.y>=0 && !visited[t.x][t.y][v.d-j] && f[t.x][t.y]=='P'){
                    t.d=v.d-j;
                    visited[t.x][t.y][t.d]=1;
                    t.time=v.time+1;
                    Q.push(t);
                }
            }
        }
    }
    cout<<"impossible"<<endl;
}
int main(){
    int i, j;
    cin>>m>>n>>d;
    memset(visited,0,sizeof(visited));
    for (int i=0;i<m;i++)
        cin>>f[i];
    bfs();
    return 0;
}