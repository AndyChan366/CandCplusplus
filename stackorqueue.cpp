#include<iostream>
using namespace std;
int main(){
    int n,a[10000],b[10000];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    int st=1,qu=1; 
    for(int i=n-1,j=0;i>=0;i--,j++){
        if(b[i]!=a[j]){
            st=0;
            break; 
        }
    }
    for(int i=0,j=0;i<n;i++,j++){
        if(b[i]!=a[j]){
            qu=0;
            break; 
        }
    }
    if(st==1&&qu==0){
        cout<<"stack"<<endl;
    }
    if(st==0&&qu==1){
        cout<<"queue"<<endl;
    }
    if(st==1&&qu==1){
        cout<<"both"<<endl;
    }
    if(st==0&&qu==0){
        cout<<"neither"<<endl;
    }
    return 0;
}
