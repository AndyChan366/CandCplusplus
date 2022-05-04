/*给定一个数列，对于其中重复的数字，只保留一个，把其余相同的数去掉，然后再把这些数从小到大排序。
输入格式：
第1行为一个正整数N，表示了数列长度。
第2行包含N个非负整数。
输出格式：
共2行，第一行为处理后数列的长度。
第二行为数字以空格隔开的处理后数列。
输入样例：
3
2 1 1
输出样例：
2
1 2*/
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    cout<<v.size()<<endl;
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
}