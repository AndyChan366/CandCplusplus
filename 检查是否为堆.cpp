#include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;
const int maxn=100000;
int a[maxn];
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    bool flag1=true,flag2=true;
    for(int j=1;j<=n/2;j++){
        if(n%2==0&&2*j>=n){
            if(!(a[j]<=a[2*j])){
                flag1=false;
                break;
            }
        }
        else if(!(a[j]<=a[2*j]&&a[j]<=a[2*j+1])){
            flag1=false;
            break;
        }
    }
    for(int j=1;j<=n/2;j++){
        if(n%2==0&&2*j>=n){
            if(!(a[j]>=a[2*j])){
                flag2=false;
                break;
            }
        }
        else if(!(a[j]>=a[2*j]&&a[j]>=a[2*j+1])){
            flag2=false;
            break;
        }
    }
    if(flag1&&flag2) cout<<"both";
    if(!flag1&&flag2)cout<<"max heap";
    if(flag1&&!flag2)cout<<"min heap";
    if(!flag1&&!flag2)cout<<"no";
}
