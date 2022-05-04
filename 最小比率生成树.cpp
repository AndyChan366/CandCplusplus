#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

const int INF = 1 << 25;
int n, m;
int map[30][30];
int wei[30];
int v[30];
int book[30];
int res[30];
double minall = INF;
void prim()
{
    int lowcost[30];
    int vis[30];
    int x = v[1];
    int sum = 0;
    memset(vis,0,sizeof(vis));
    for(int i = 1; i <= m; i ++)
        lowcost[v[i]] = map[x][v[i]];
    vis[x] = 1;
    for(int i = 1; i <= m; i ++)
    {
        int minx = INF;
        for(int j = 1; j <= m; j ++)
        {
            if(!vis[v[j]] && lowcost[v[j]] < minx)
            {
                x = v[j];
                minx = lowcost[v[j]];
            }
        }
        vis[x] = 1;
        if(minx != INF)
            sum += minx;  
        for(int j = 1; j <= m; j ++)
        {
            if(!vis[v[j]] && lowcost[v[j]] > map[x][v[j]])
                lowcost[v[j]] = map[x][v[j]];
        }
    }
    int sumn = 0;
    for(int i = 1; i <= m; i ++)
        sumn += wei[v[i]];
    double minthis = (sum*1.0) / (sumn*1.0);
    if(minthis < minall)
    {
        for(int i = 1; i <= m; i ++)
            res[i] = v[i];
        minall = minthis;
    }
}
void dfs(int x,int cnt)  
{  
    if(x == m + 1)
    {
        prim();
        return ;
    }
    for(int i = cnt;i <= n;i++)  
    {  
        if( !book[i] )  
        {  
            book[i] = 1;  
            v[x] = i;   
            dfs( x+1,i+1);  
            book[i] = 0;  
        }  
    }  
}  
int main()
{
    while(cin >> n >> m && n | m)
    {
        minall = INF;
        memset(book,0,sizeof(book));
        for(int i = 1; i <= n; i ++)
            cin >> wei[i];
        for(int i = 1; i <= n; i ++)
            for(int j = 1; j <= n; j ++)
                cin >> map[i][j];
        dfs(1,1);
        sort(res + 1, res + m + 1);
        for(int i = 1; i < m; i ++)
            cout << res[i] << " ";
        cout << res[m] << endl;
    }
    return 0;
}