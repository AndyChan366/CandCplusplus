/*
高兴同学想实践哈希表的查找和插入。为此，他定义了下面的查找和插入函数：int find_and_insert(vector<int> & table, int k);
假定关键字是非负整数，table是他要建立的哈希表，k是查找和插入的关键字。函数的功能如下：
如果查找成功，则返回关键字的比较次数，如果查找失败，则将k插入到合适的位置，并返回关键字的比较次数。
为简单起见，高兴决定使用线性探查法，并使用下列的简单哈希函数：h(k) = k % table.size();
请你给出查找和插入函数的实现，并且你只需提交实现的函数。
*/
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
int find_and_insert(vector<int> & table, int k){
    int flag;
    int hk;
    vector<int>::iterator it=find(table.begin(),table.end(),k);
    if(it!=table.end()){
        hk=k%table.size();
        flag=distance(table.begin(),it);
        return (hk<=flag?flag-hk+1:hk+table.size()-flag+1);
    }
    else{
        hk=k%table.size();
        if(table[hk]==-1){
            table[hk]=k;
            return 1;
        }
        else{
            int coun=1;
            while(table[hk]!=-1){
                hk=(hk+1)%table.size();
                coun++;
            }
            table[hk]=k;
            return coun;
        }
    }
}
int main(){
    //测试用例：
    vector<int> table={11,12,24,36,45,-1,72,84,-1,-1,21};
    // cout<<table.size();
    // for(auto ch:table){
    //     cout<<ch<<" ";
    // }
    int M,k;
    cin>>M;
    for(int i=0;i<M;i++){
        cin>>k;
        cout<<find_and_insert(table,k)<<endl;
        for(auto ch:table){
            cout<<ch<<" ";
        }
    }
}
