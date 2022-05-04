/*在无限的整数序列1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, …中找到第n个数字。
说明：题目中“第n个数字”指0-9，例如，第10个数字为1，第11个数字为0，共同对应着整数序列中的10。
input：
第一行为t，表示测试组数；
接下来t行，每行有一个整数n。
output：
输出t行，每行一个数字。
示例输入：
2
3
11
示例输出：
3
0
*/
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n<=9) cout<<n<<endl;
        else{
            int len=0;
            long long digit=pow(10,len)*(len+1)*9;
            while(n>digit){
                n-=digit;
                len+=1;
                digit=pow(10,len)*(len+1)*9;
            }
            string res=to_string((long long)(pow(10,len)+(n-1)/(len+1)));
            int ans=res[n-(n-1)/(len+1)*(len+1)-1]-'0';
            cout<<ans<<endl;  
        }   
    }
}