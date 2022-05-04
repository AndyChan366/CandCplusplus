#include<iostream>
#include<algorithm>
#include<map>
#include<iomanip>
using namespace std;
struct vec{
    int num,index;
};
bool cmp(const vec &a, const vec &b){
	if(a.num==b.num)return a.index<b.index;
	else return a.num<b.num; 
}
int main(){
    vec a[10000];
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i].num;
        a[i].index=i;
    }
    sort(a,a+n,cmp);
    for(int i=0;i<n-1;i++){
        cout<<a[i].index+1<<" ";
    }
    cout<<a[n-1].index+1<<endl;
    long long sum=0;
    for(int i=0;i<n;i++){
        sum+=(a[i].num*(n-i-1));
    }
    cout<<setprecision(2)<<fixed<<sum/((double)n)<<endl;
}