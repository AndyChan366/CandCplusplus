#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
    int n;
    long mod=1000000007;
    long res=0;
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++){
        cin>>A[i];
    } 
    for (int i = 0; i<n; i++) {
        int l = i-1;
        for (; l>=0 && A[i] < A[l]; l--) ;
        int r = i+1;
        for (; r<n && A[i] <= A[r]; r++) ;
        res += (i-l)*(r-i)*A[i];
    }
    cout<<(int)(res % mod);
}
