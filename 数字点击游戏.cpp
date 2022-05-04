#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
const int N=1e6;
long long u,v,p,a[N],b[N+10],l=1,r=0,total;
map<long long,long long> prefow,visited,optfow,preback,optback;
void swap(long long &x,long long &y){
    long long temp;
    temp=x;
    x=y;
    y=temp;
}
//快速幂算法(针对第3种操作).
long long quickpower(long long d,long long k){
    long long f=1;
    while(k){
        if(k&1)f=f*d%p;
        d=d*d%p;
        k>>=1;
    }
    return f;
}
//正向搜索:now代表现在的u,to代表计算后的u,op代表第几种操作(1,2,3).
void turnfow(long long now,long long to,long long op){
    if(!visited[to]){
        visited[to]=1;
        optfow[to]=op;
        prefow[to]=now;
        b[++r]=to;
    }
}
//正向BFS
int bfsfow(){
    b[++r]=u;
    while(l<=r&&r<=N){
        long long now=b[l++];
        if(now==v){
            while(now!=u){
                a[++total]=optfow[now];
                now=prefow[now];
            }
            cout<<total<<endl;
            return 1;
        }
        long long to;
        //三种情况：
        to=(now+1)%p;
        turnfow(now,to,1);
        to=(now+p-1)%p;
        turnfow(now,to,2);
        to=quickpower(now,p-2);
        turnfow(now,to,3);
    }
    return 0;
}
//反向搜索;now,to,op同上.
void turnback(long long now,long long to,long long op){
    if(!visited[to]){
        visited[to]=1;
        optback[to]=op;
        preback[to]=now;
        b[++r]=to;
    }
}
//反向BFS
void bfsback(){
    visited.clear();
    l=1,r=0;
    b[++r]=v;
    while(l<=r&&r<=N){
        long long now=b[l++];
        if(prefow.find(now)!=prefow.end()){
            long long t=now;
            while(now!=u){
                a[++total]=optfow[now];
                now=prefow[now];
            }
            for(int i=1;i<=total>>1;i++){
                swap(a[i],a[total+1-i]);
            }
            now=t;
            while(now!=v){
                a[++total]=optback[now];
                now=preback[now];
            }
            cout<<total<<endl;
            return;
        }
        //两种情况（反向搜索时）：
        long long to;
        to=(now+1)%p;
        turnback(now,to,2);
        to=(now+p-1)%p;
        turnback(now,to,1);
        to=quickpower(now,p-2);
        turnback(now,to,3);
    }
}
int main(){
    cin>>u>>v>>p;
    if(bfsfow())return 0;
    bfsback();
    return 0;
}
