/*给定一个非负整数数组，你位于数组的第一个位置。数组中的每个元素代表你在该位置可以跳跃的最大长度。你的目标是使用最少的跳跃次数到达数组的最后一个位置。
输入：
第一行输入测试样例T，对于每个样例，先输入n，表示数组长度，接着输入一个大小为n的数组序列。
输出：
对于每个样例，输出一个整数，表示最小跳跃次数。
输入样例：
1
5
2  3  1  1  4
输出样例：
2*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;
int jump(vector<int>& nums){
    int n=nums.size();
    int dp[n];
    memset(dp,9999999,sizeof(dp));  
    dp[0]=0;  
    for(int i=0;i<n;i++){
        for(int j=1;j<=nums[i]&&i+j<n;j++){
            dp[i+j]=min(dp[i+j],dp[i]+1);
        }
    }       
    return dp[n-1];
}
int main(){
    int t,n,a;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> v;
        for(int i=0;i<n;i++){
            cin>>a;
            v.push_back(a);
        }
        cout<<jump(v)<<endl;
    }
}

