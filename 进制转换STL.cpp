#include<iostream>
#include<stack>
#include<vector>
using namespace std;
int main(){
	int n,t;
	stack<int> q;
	vector<int> a;
	cin>>n;
	while(n){
		t=n%10;
		q.push(t);
		n/=10;
	}
	while (!q.size()){
		a.push_back(q.top());
		q.pop();  
	} 
	for(int i=0;i<a.size();i++){
		cout<<a[i]<<" ";
	}
}
