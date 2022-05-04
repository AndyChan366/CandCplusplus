#include<iostream>
using namespace std;
int res[100001];
void divide(int n, int m, int k){
    if(m>=k)return;
    if(m==0 || res[m]<=res[m-1]){
        int i;
        for(i=0;i<=m;i++){
            cout<<res[i];
        }
        for(;i<k;i++){
            cout<<0;
        }
        cout<<endl;
    }
    for(int i=n-1;i>=1;i--){
        res[m]=i;
        res[m+1]=n-i;
        if(m==0 || res[m]<=res[m-1]){
            divide(n-i,m+1,k);
        }
    }
}
int main() {
    int t,m,n;
    cin>>t;
    while(t--){
        cin>>m>>n;
        res[0]=m;
        divide(m,0,n);
    }
    return 0;
}                                 