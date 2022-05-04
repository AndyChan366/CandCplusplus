#include<iostream>
using namespace std;
int f(int m,int n){
    if(m==0 || m==1)
        return 1;
    if(n==1)
        return 1;
    if(m<n)
        return f(m,m);
    else
        return f(m,n-1)+f(m-n,n);
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int m,n;
        cin>>m>>n;
        cout<<f(m,n);
    }
    return 0;
}