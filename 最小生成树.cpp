/*高兴同学想为家乡的脱贫致富贡献一点力量，计划帮助县政府实现乡乡通光纤网络。为此，他需要寻求一个最优或者最低费用的光纤铺设方案。
假设每个乡都用数字1至N表示，每条光纤连接两个乡，光纤只在两个乡汇合。假设你是高兴同学，请你计算一个最小费用方案。
输入：
第一行是测试样例数目t。
对于每个测试样例，第一行是一个整数N (3 <= N <= 500),表示该县有N个乡。
接下来是N行输入，其中第i行含N个整数，而且第j个整数表示i乡与j乡用光纤连接的费用c (1 <= c <= 65536)。
输出：
对每个测试样例，输出你的最小费用设计方案的费用。每个输出占一行。
输入样例：
1
3
0 990 692
990 0 179
692 179 0
输出样例：
871*/
#include<iostream>
#include<string.h>
using namespace std;
const int INF=0x3f3f3f;
const int MAXN=501;
int a[MAXN][MAXN];
int dis[MAXN];
bool visited[MAXN];
int prim(int n){
	int sum=0;
    int visit,max_line = -INF,min_path;
    memset(visited,false,sizeof(visited));
    visited[0]=true;
    for(int i=0;i<n;i++)
        dis[i]=a[0][i];
    for(int j=1;j<n;j++){
        min_path=INF;
        for(int i=0;i<n;i++){
            if(visited[i]==false && min_path>dis[i]){
                visit=i;
                min_path=dis[i];
            }
        }
		sum+=min_path;
        // cout<<min_path<<endl;
        // if(max_line<min_path)max_line = min_path;
        visited[visit]=true;
        for(int i=0;i<n;i++){
			if(visited[i]==false && dis[i]>a[visit][i]){
				dis[i]=a[visit][i];
			}
		}      
    }
    return sum;
}
int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin>>a[i][j];
			}
		}      
        cout<<prim(n)<<endl;
    }
    return 0;
}
