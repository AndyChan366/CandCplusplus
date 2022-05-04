/*希尔排序实现：若去掉第20行的while循环则为排序一趟的结果（即每increment个数一组，组内是排好序的）。
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void insert_sort(vector<int> &v){
    for(int i=1;i<v.size();++i){
        int temp=v[i];
        int pos=i;
        for(int j=i-1;j>=0&&temp<v[j];--j){
            v[j+1]=v[j];
            pos=j;
        }
        v[pos]=temp;
    }
}
void shell_once(vector<int> &v,int increment){
    int i,j,k;
    while(increment>1){
        increment=increment/3+1;
        for(i=0;i<increment;++i){
            for(j=i+increment;j<v.size();j+=increment){
                int temp=v[j];
                int pos=j;
                    for(k=j-increment;k>=0&&v[k]>temp;k-=increment){
                        v[k+increment]=v[k];
                        pos=k;
                    }
                v[pos]=temp;
            }
        }
    }
}

int main(){
    vector<int> a={3,1,5,6,7,9,2,4,8};
    shell_once(a,3);
    for(auto ch:a){
        cout<<ch<<" ";
    }
}