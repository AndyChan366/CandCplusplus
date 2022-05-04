#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int c=0;
	for(int i=0;i<n-1;i++){
		c+=max(0,a[i+1]-a[i]);
	} 
	cout<<c;
}
