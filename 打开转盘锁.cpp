#include<iostream>
#include<unordered_set>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

int open(vector<string>& deadends, string target){
    unordered_set<string> visited;
    visited.insert(deadends.begin(),deadends.end()); 
    if(visited.count("0000")) 
        return -1;
    int res=0;
    queue<string> st;
    st.push("0000");
    while(!st.empty()){            
        int length=st.size();
        for(int i=0;i<length;i++){
            string cur=st.front();
            st.pop();
            if(cur==target)
                return res;
            for(int j=0;j<4;++j){
                for(int t=-1;t<2;t+=2){
                    char c=(cur[j]-'0'+10+t)%10+'0';
                    string curr=cur;
                    curr[j]=c;
                    if(!visited.count(curr)){
                        st.push(curr);
                        visited.emplace(curr);
                    }
                }                 
            }
        }
        res++;
    }
    return -1;
}

int main(){
    string target;
    cin>>target;
    int n;
    cin>>n;
    vector<string> deadends(n);
    for(int i=0;i<n;i++){
        string dead;
        cin>>dead;
        deadends.push_back(dead);
    }
    vector<string>::iterator it;
	it=find(deadends.begin(),deadends.end(),target);
	if(it!=deadends.end()){
        cout<<4<<endl;
    }
    else{
        cout<<open(deadends,target)<<endl;
    }
}