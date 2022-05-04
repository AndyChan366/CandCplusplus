#include<iostream>
#include<string>
#include<cstring>
using namespace std;
#define N 205
int ans[100],k;
string preorder,midorder;
int dfs(int l,int r){
	if(l==r)return ans[preorder[k++]]=1;
	int curr=l,temp=preorder[k];
	while(midorder[curr]!=preorder[k])++curr; 
	++k;
	if(curr>l) ans[temp]+=dfs(l,curr-1);
	if(curr<r) ans[temp]+=dfs(curr+1,r);
	return ans[temp];
}
int main(){
	cin>>preorder>>midorder;
	// scanf("%s\n%s",preorder,midorder);
	int n=preorder.size();
	dfs(0,n-1);
	for(int i=0;i<n;i++){
		for(int j=1;j<=ans[preorder[i]];j++){
			cout<<preorder[i];
		}
		cout<<endl;
	}
	return 0;
}
