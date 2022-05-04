#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	} 
	sort(a,a+n);
	int b=0;
	if(a[n-2]!=a[n-1])b=a[n-1];
	else if(a[0]!=a[1])b=a[0];
	else{
		for(int i=0;i<n;i++){
			if(a[i]!=a[i+1]&&a[i+1]==a[i+2])b=a[i];
		}
	}
	cout<<b;
}
