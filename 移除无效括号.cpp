/*给定由若干括号与字母组成的字符串s，删除最小数量的无效括号，使括号匹配。
输入：
一行，字符串s。
输出：
大于等于0行，每行为一种可能的结果。
按字典序排列。
输入样例：
()())()
输出样例：
(())()
()()()
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<unordered_set>
using namespace std;


bool isValid(string s){
    int coun=0;
    for(auto ch:s){
        if(ch=='(') coun++;
        else if(ch==')') coun--;   
        if(coun<0) return false;
    }
    return coun==0;
}

vector<string> remvinvalid(string s){
    vector<string> ans;
    if(s.empty()) return {""};
    if(isValid(s)) return {s};
    queue<string> q;
    unordered_set<string> visited; 
    q.push(s);
    visited.insert(s);
    while(!q.empty()){
        int n=q.size();
        for(int i=0;i<n;i++){
            string cur=q.front(); q.pop();
            for(int i=0;i<cur.size();i++){
                string temp=cur;
                if(temp[i]!='(' && temp[i]!=')') continue;
                string curr=temp.erase(i, 1);  
                if(visited.count(curr)==0 && isValid(curr)) ans.push_back(curr);
                else if(visited.count(curr)==0) q.push(curr);
                visited.insert(curr);
            }
        }
        if(!ans.empty()) return ans; 
    }
    return ans;
}

int main(){
    string s;
    cin>>s;
    vector<string> ans=remvinvalid(s);
    sort(ans.begin(),ans.end());
    for(auto ch:ans){
        cout<<ch<<endl;
    }
}
