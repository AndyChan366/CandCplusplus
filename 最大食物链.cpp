#include<iostream>
#include<cstdio>
using namespace std;
const int Max = 10001;
struct node{
    int y,ne;
}a[Max];
int head[Max],sum = 0;
int input[Max],out[Max],dp[Max];
int ans = 0;
void add(int x,int y){
    a[++sum].y = y;
    a[sum].ne = head[x];
    head[x] = sum;
}
int dfs(int x){
    if(dp[x] != 0)return dp[x];
    int ans = 0;
    if(input[x] != 0 && out[x] == 0)
        ans ++;
    for(int i = head[x];i != 0;i = a[i].ne){
        ans += dfs(a[i].y);
    }
    dp[x] = ans;
    return ans;
}
int main(){
    int n,m;
    cin >> n >> m;
    int a,b;
    for(int i = 1;i <= m;++ i){
        cin >> a >> b;
        add(a,b);
        out[a] ++;
        input[b] ++;
    }
    int total = 0;
    for(int i = 1;i <= n;i++)
        if(input[i] == 0 && out[i] != 0)
            total+= dfs(i);
    cout << total<< endl;
    return 0; 
}
