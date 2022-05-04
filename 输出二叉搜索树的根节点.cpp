/*给定一个序列，构建二叉搜索树，对于非根节点，按照输入顺序给出每个节点的父亲节点。
Examples：
Input：
3
1 2 3
Output：
1 2
Input：
5
4 2 3 1 6
Output：
4 2 2 4*/
#include<iostream>
#include<map>
#include<set>
using namespace std;
const int maxn=10000;
int a[maxn];
set<int> root;
map<int,int> l;
map<int,int> r;
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    root.insert(a[0]);
    int ans;
    for(int i=1;i<n;i++){
        set<int>::iterator pos=root.lower_bound(a[i]);
        if(pos!=root.end()&&l[*pos]==0){
            ans=*pos;
            l[*pos]=a[i];
        }
        else{
            pos--;
            ans=*pos;
            r[*pos]=a[i];
        }
        cout<<ans<<' ';
        root.insert(a[i]);
    }
    cout<<endl;
    return 0;
}