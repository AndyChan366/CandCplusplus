/*实现下列函数，返回v中第k个最小元的函数：
int select_kth_smallest(vector<int> &v, size_t k);
*/
//注：改题目很容易，正常来讲直接sort即可；但所给vector的size在100000左右，所以会卡时间和空间，因此要用更快的排序算法。
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
template<typename T>
void sort1(T begin, T end){
    int m[100001]={};
    for(auto it=begin;it!=end;++it){
        ++m[*it];
    }
    auto it=begin;
    for(auto i=0;i<100001;++i){
        for(auto j=0;j<m[i];++j){
            *it++=i;
        }
    }
}
int select_kth_smallest(vector<int> &v, size_t k){
    sort1(v.begin(),v.end());
    return v[k-1];
}
int main(){
    //测试用例：
    vector<int> v={2,3,4,5,6,7,10,1,9,122,8,12,13};
    size_t k=3;
    cout<<select_kth_smallest(v,k)<<endl;
    sort(v.begin(),v.end());
    cout<<v[k-1];
}
