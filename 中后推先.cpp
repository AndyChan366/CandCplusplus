#include<iostream>
#include<string>
#include<cstring>
#include<string.h>
using namespace std;
char post[100],mid[100];
void pre(int root,int start,int end){
	if(start>end)return ;
	int i=start;
	while(i<end&&mid[i]!=post[root])
		i++;
	cout<<post[root];
	pre(root-1-end+i,start,i-1);
	pre(root-1,i+1,end);
}
int main(){
	int n,i;
	cin>>mid>>post;
	n=strlen(mid);
	pre(n-1,0,n-1);
	return 0;
}

