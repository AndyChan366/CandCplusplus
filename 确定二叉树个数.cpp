/*输入格式：
整个输入有两行，第一行给出前序遍历的访问顺序，第二行给出后序遍历的访问顺序。
二叉树的结点用一个大写字母表示，不会有两个结点标上相同字母。输入数据不包含空格，且保证至少有一棵二叉树符合要求。
输出格式：
输出一个整数，为符合要求的不同形态二叉树的数目。
样例输入：
ABCD
CBDA
样例输出：
2*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
char PreStr[10000];
char PostStr[10000];
int coun;
void calc(int a1,int b1,int a2,int b2){
    int i;
    if(a1>=b1)return;
    for(i=a2;i<=b2-1;i++){
        if(PreStr[a1+1]==PostStr[i])break;
    }
    if(i==b2-1)coun++;
    calc(a1+1,a1+1+(i-a2),a2,i);
    calc(a1+1+(i-a2)+1,b1,i+1,b2-1);
}
 
int main(){
    cin>>PreStr;
    cin>>PostStr;
    int len=strlen(PreStr);
    coun=0;
    calc(0,len-1,0,len-1);
    long long ans=(long long)(pow(2,coun));
    cout<<ans<<endl;
}