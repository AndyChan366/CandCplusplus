/*题目大意：n个塔，从右往左激活，每激活一个塔，这个塔将把它伤害范围内的塔全部摧毁（这个塔本身没有摧毁）。
现要求然后在最右边再加一个塔（位置不定，伤害范围不定），问最少被摧毁的塔的数量。*/
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
const int N=100001;
int a[N],b[N],influ[10*N],visited[10*N],dp[10*N];
int main(){
	int n;
    cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		visited[a[i]]=1;
        influ[a[i]]=b[i];
	}
	int ans=0;
	for(int i=0;i<10*N;i++){
		if(!visited[i])dp[i]=dp[i-1];
		else{
			if(influ[i]>=i)dp[i]=1;
			else dp[i]=dp[i-influ[i]-1]+1;
		}
		ans=max(ans,dp[i]);
	}
	cout<<(n-ans)<<endl;
}

