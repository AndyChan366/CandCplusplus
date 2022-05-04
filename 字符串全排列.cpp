#include <iostream>
#include<algorithm> 
#include<vector>
#include<string> 
using namespace std;
int main(){
	string s;
	string t;
	cin>>s;
	int n=s.size();
	int a[n];
	for(int i=0;i<s.size();i++)
	a[i]=(int)(s[i]-'a');
	do{
		for(int i=0;i<n;i++){
			t[i]=(char)(a[i]+'a');
			cout<<t[i];
		}
		cout<<endl;
	}while(next_permutation(a,a+n));
}


