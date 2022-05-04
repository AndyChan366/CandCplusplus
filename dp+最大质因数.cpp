#include<iostream>
#include<cmath>
using namespace std;
int dp[10000]; 
int GetMaxPrime(int num){
    int ans, i = 2;
    while (i * i <= num) {
        if (num % i == 0) ans = i;
        while (num % i == 0) num /= i;
        i++;
    }
    if (num != 1) ans = num;
    return ans;
}
int f(int n){
	dp[0]=0;
	dp[1]=1;
	for(int i=2;i<10000;i++){
		dp[i]=99999;
	}
	for(int i=2;i<=n;i++){
		dp[i]=min(dp[i-1],dp[GetMaxPrime(i)])+1;
	}
	return dp[n];
}
int main(){
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		cout<<f(n)<<endl;
	}
}
