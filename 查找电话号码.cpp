/*
问题描述：
输入是某电话公司的若干客户姓名及电话号码，中间用逗号分隔，然后是若干要查询的客户姓名，输出是这些查询的客户姓名及其电话。
输入：
第一行是一个正整数n(不超过100000)，表示某电话公式的客户个数。
然后是n个客户，每个客户占一行，由一个字符串构成的姓名和一个电话号码组成，中间用逗号分隔，每个姓名的长度不超过45。
接下来是一个正整数m，然后是m个需要查询的客户姓名，每个姓名占一行。
输出：
对于每个查询的客户，如果该客户是电话公式的客户，则显示其姓名和电话号码，如果不存在，则显示姓名和‘No’，中间用‘：’分隔。每个输出占一行。
输入：
4
Bob,34778654
Ana,567894833
Alice,3456789
Gates,6893838
5
Alice
bob
Gate
Bob
Ana
输出：
Alice:3456789
bob:No
Gate:No
Bob:34778654
Ana:567894833
*/

#include<iostream>
#include<string.h>
#include<cstring>
#include<map>
#include<vector>
#include<string>
using namespace std;
int main(){
    map<string,string> mymap;
    int K,Q;
    cin>>K;
    string str0,str1,str2;
    for(int k=0;k<K;k++){
        cin>>str0;
        str1=str0.substr(0,str0.find(","));
        str2=str0.substr(1+str0.find(","),str0.size()-1);
        // cout<<str1<<str2;
        mymap.insert(make_pair(str1,str2));
    }
    cin>>Q;
    for(int q=0;q<Q;q++){
        string str3;
        cin>>str3;
        auto it=mymap.find(str3);
        if(it==mymap.end())cout<<str3<<":No"<<endl;
        else cout<<str3<<":"<<it->second<<endl;
    }
}