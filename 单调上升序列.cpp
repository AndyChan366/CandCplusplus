/*问题描述:
给定一长度为n的数列，请在不改变原数列顺序的前提下，从中随机的取出一定数量的整数，并使这些整数构成单调上升序列。 输出这类单调上升序列的最大长度。
输入格式：
第一行，一正整数n，表示数列的长度
第二行，n个数，表示数列
输出格式：
一行，一个整数。
输入样例：
5
3 1 5 4 2
输出样例：
2*/
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int main(){
    int n,i,j,dp[101],x[101],len=0;
        cin>>n;
        for(i=0;i<n;i++){
            cin>>x[i];
        }
        dp[0]=1;
        for(i=1;i<n;i++){
            dp[i]=1;
            for(j=0;j<i;j++){
                if(x[i]>x[j])
                    dp[i]=max(dp[i],dp[j]+1);
            }
        }
        for(i=0;i<n;i++){
           len=max(len,dp[i]);
        }
        cout<<len<<endl;
    }


