/*设有n个正整数，将它们联接成一排，组成一个最大的多位整数。
输入格式:
第一行，一个正整数n。
第二行，n个正整数。
输出格式:
一个正整数，表示最大的整数。
输入样例:
3
13 312 343
输出样例:
34331213*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

bool cmp(string i,string j){
    return (i+j)>(j+i);
}

int main(){
    int n;
    cin>>n;
    string num;
    while(n--){
        vector<string> temp;
        while(cin>>num){
            temp.push_back(num);
            if(getchar()=='\n')break;
        }
        sort(temp.begin(),temp.end(),cmp);  
        for(auto ch:temp){
            cout<<ch;
        }
        cout<<endl;
    }
    
}
