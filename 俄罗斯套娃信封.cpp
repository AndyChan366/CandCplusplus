/*当一个信封的宽度和高度都比另一个信封大，这个信封就能被套进另一个信封里。
给定n个信封的宽高，计算最多能有多少个信封能被套到一起。
不能旋转信封。
输入:
第一行输入为n，接下来n行每行包含宽w与高h。
输出:
一个数字。
示例输入:
4
5 4
6 4
6 7
2 3
示例输出:
3*/
#include<iostream>
#include<algorithm>
#include<vector>
// #include<pair>
using namespace std;
int taowa(vector<pair<int,int> >& v){
    int n=v.size(),res=1;
    if(n==0)return 0;
    sort(v.begin(),v.end());
    vector<int> ans(n,1);
    for(int i=1;i<n;i++){
        auto it=v[i];
        for(int j=i-1;j>=0;j--){
            auto itt=v[j];
            if(it.first>itt.first && it.second>itt.second){
                ans[i]=max(ans[i],ans[j]+1);
            }
            res=max(res,ans[i]);
        }
    }
    return res;
}
int main(){
    int n,a,b;
    cin>>n;
    vector<pair<int,int> > v; 
    for(int i=0;i<n;i++){
        cin>>a>>b;
        v.emplace_back(a,b);
    }
    cout<<taowa(v)<<endl;
}