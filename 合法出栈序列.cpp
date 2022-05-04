#include<iostream>
#include<cstring>
#include<map>
#include<vector>
#include<stack>
using namespace std;
 
bool judge(vector<int> in,vector<int> out){
    if(in.size()==0){
        return true;
    }
    if(in.size()!=out.size()){
        return false;
    }
    stack<int> st;
    int j=0;
    for(int i=0;i<in.size();++i){
        st.push(in[i]);
        while(!st.empty()&&st.top()==out[j]){
            st.pop();
            j++;
        }
    }
    return st.empty();
}

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int siz,a;
        cin>>siz;
        vector<int> v1(siz);
        vector<int> v2(siz);
        for(int i=0;i<siz;i++){
            cin>>a;
            v1.push_back(a);
        } 
        for(int i=0;i<siz;i++){
            cin>>a;
            v2.push_back(a);
        } 
        bool res=judge(v1,v2);
        if(res){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
	return 0;
}