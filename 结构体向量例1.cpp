#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct student{
	string name;
	int fenshu;
};
static bool cmp(student a,student b){
	if(a.fenshu>b.fenshu)return true;
	else if(a.fenshu==b.fenshu)return a.name>b.name;
	return false;
}
int main(){
	vector<student> s;
	vector<student>::iterator it;
	student stu;
	int n=4;
	string t;
	int m;
	while(n--){
		cin>>t>>m;
		stu.name=t;
		stu.fenshu=m;
		s.push_back(stu);
	}
	for(it=s.begin();it!=s.end();it++){
		cout<<it->name<<" "<<it->fenshu<<" "; 
	}
	sort(s.begin(),s.end(),cmp);
	cout<<endl;
	for(it=s.begin();it!=s.end();it++){
		cout<<it->name<<" "<<it->fenshu<<" "; 
	} 
}

