#include <iostream>
#include <string.h>
#include <cstring>
#include <string>
using namespace std;
char pre[100];
char mid[100];
char post[100];
int len;
void FindPost(int p1,int p2,int m1,int m2)
{
	if (p1<=p2)
	{
		int i;
		for (i=m1;i<=m2;i++)
		{
			if (mid[i]==pre[p1]) break;
		}
		post[--len] = pre[p1];
		FindPost(p1+(i-m1)+1,p2,i+1,m2);
		FindPost(p1+1,p1+(i-m1),m1,i-1);
	}
	else
		return;
}
int main()
{
	while(cin>>pre>>mid)
	{
		int n = strlen(pre);
		len = n;
		FindPost(0,n-1,0,n-1);
		int i;
		cout<<post<<endl;
	}
	return 0;
}
