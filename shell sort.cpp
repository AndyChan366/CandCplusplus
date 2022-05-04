#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void shell_once(vector<int> &v, int increment){
    int div=v.size()/increment;
    for(int i=0;i<=div;++i){//分组成div组
        for(int j=i;j<v.size()-div;j+=div){//对每组进行插入排序
            for(int k=j;k<v.size();k+=div){
                if(v[j]>v[k])swap(v[j],v[k]);//交换两个数的值
            }
        }
    }
}
int main(){
    vector<int> a={3,1,5,6,7,8,2,4,9};
    shell_once(a,3);
}