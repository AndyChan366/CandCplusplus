#include<iostream>
using namespace std;
int main(){
    long long dp[101][101];
	int n,h; 
	cin>>n>>h;
	for(int i=0;i<=n;i++){
        dp[0][i]=1; 
    }
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=0;k<j;k++){
				dp[j][i]+=dp[k][i-1]*dp[j-1-k][i-1];
			} 
		}
	}
	cout<<dp[n][n]-dp[n][h-1]<<endl; 
	return 0;
}
