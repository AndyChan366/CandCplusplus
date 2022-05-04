#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int judge(string s,string t){
    if(s.size()!=t.size())return 0;
    int n=s.size();
    vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(n+1,0)));
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
            dp[i][j][1]=(s[i]==t[j]);
    for(int k=2;k<=n;++k){
        for(int i=0;i+k<=n;++i){
            for(int j=0;j+k<=n;++j){
                for(int ck=1;ck<k;++ck){
                    dp[i][j][k]|=((dp[i][j][ck]&&dp[i+ck][j+ck][k-ck])||(dp[i][j+k-ck][ck]&&dp[i+ck][j][k-ck]));
                }
            }
        }
    }
    return dp[0][0][n];
}
int main(){
    string s1,s2;
    cin>>s1;
    cin>>s2;
    cout<<judge(s1,s2)<<endl;
}