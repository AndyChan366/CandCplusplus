#include<iostream>
#include<queue>
#include<vector>
#include<map>
using namespace std;
/*struct Node{
    int x, y;
}node;*/
struct cmp{
    bool operator()(const pair<int,int>& a,const pair<int,int> b){
        if(a.first + a.second > b.first + b.second)	return true;
        else if(a.first + a.second == b.first + b.second)	return a.first < b.first;
        return false;
    }
};
int main(){
    priority_queue<pair<int, int>,vector<pair<int,int> >,cmp>q;
    int k,m,n;
    cin>>k>>m>>n;
    vector<int> a(m);
 	vector<int> b(n);
    for(int i=0;i<m;i++){
    	cin>>a[i];
    }
    for(int i=0;i<n;i++){
    	cin>>b[i];
    }
    if(k>=m*n){
    	for(int i=0;i<m;i++){
    		for(int j=0;j<n;j++){
    			cout<<a[i]<<","<<b[j]<<' '; 
			}
		}
	}
	else{
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                q.push(make_pair(a[i],b[j]));
            }    
        }
        while(k--){
            cout<<q.top().first<<","<<q.top().second<<' ';
            q.pop();
        }
    }
}
