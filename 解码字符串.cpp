#include<iostream>
#include<cstring>
#include<string> 
using namespace std;
int main(){
	string S;
	int K;
	cin>>S;
	cin>>K;
    long long si=0;
    int j,i;
    for(j=0;j<S.size()&&si<K;j++){
        if(isdigit(S[j]))
        si*=(S[j]-'0');
        else si++;
    }
    for(i=j-1;i>=0;i--){
        K%=si;
        if(K==0&&!isdigit(S[i])){
        cout<<S[i];
        break;
    }
    if(isdigit(S[i])) si/=(S[i]-'0');
    else si--;
    }
    cout<<"";
}

