/*
高兴同学在一家电话公司实习。电话公司有一个长长的用户信息列表，公司需要根据用户的姓名、电话和地址查询相关信息。
公司老板请高兴同学帮忙设计一个便于实现这些查询的程序。高兴同学需要分别为用户姓名、电话和地址设计三个索引数组。
姓名的索引数组是按照姓名排列时，用户在用户列表中位置的列表。例如，假如用户信息列表是包含姓名、电话和地址的列表：
[(Wang, 123456, address1), (Gao, 23456, address2), (Li, 55688, address3), (Hao, 56788, address4)]；
那么姓名的索引数组是[1, 3, 2, 0]，即按照用户姓名的字典序列出这些用户的在列表中的序号（序号从0开始）。
解释：排第1位的是列表中“Gao”用户，下一位是"Hao"用户, 下一位是"Li"，最后一位是"Wang"用户。
现在，请你根据用户列表，创建姓名的索引数组，将其实现在如下函数中：vector<int> accessArray(const vector<Customer> & table)。
*/
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

struct Customer {
    string name;
    string phone;
    string address;
};
bool operator == (const Customer &d,const Customer &e){
    return (d.name==e.name) and (d.phone==e.phone) and (d.address==e.address);
}
bool cmp(Customer a,Customer b){
    if(a.name<b.name)return true;
    return false;
}

vector<int> accessArray(const vector<Customer> & table){
    vector<Customer> cp(table);
    sort(cp.begin(),cp.end(),cmp);
	vector<int> ans;
    for(auto ch:cp){
        int coun=0;
        for(auto x:table){
            if(!(ch==x))coun++;
            if(ch==x){
                ans.push_back(coun);
                break;
            }
        }
    }
    return ans;
}

int main(){
    // 测试用例：
	vector<Customer> arr;
	arr.push_back({"Wang", "123456", "address1"});
    arr.push_back({"Gao", "23456", "address2"});
    arr.push_back({"Li", "55688", "address3"});
    arr.push_back({"Hao", "56788", "address4"});
    vector<int> res=accessArray(arr);
    for(auto p:res){
        cout<<p<<" ";
    }
}
