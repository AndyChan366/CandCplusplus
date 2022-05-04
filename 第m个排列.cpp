/*给定n，有集合[1, 2, ... , n]，显然集合共有n!种排列。
按字典序列出排列，如n == 3，有:
123
132
213
231
312
321
找出集合的第k个排列。
示例输入:
3 3
示例输出:
213
*/
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
string nextpermutation(int n,int m){
    string res;
    string num="123456789";
    vector<int> index(n,1);
    for(int i=1;i<n;++i){
        index[i]=index[i-1]*i;
    }
    m=m-1;
    for(int i=n;i>=1;--i){
        int j=m/index[i-1];
        m%=index[i-1];
        res.push_back(num[j]);
        num.erase(j, 1);
    }
    return res;
}
int main(){
    int m,n;
    cin>>n>>m;
    cout<<nextpermutation(n,m)<<endl;
}