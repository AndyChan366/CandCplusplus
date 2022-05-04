#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct edge_str{
    int posx,posy;
    //查找结构体e是否存在
    bool operator == (const edge_str &e){
        return (this->posx == e.posx) && (this->posy == e.posy);
    }
    //查找数值pos是否与posx相等
    bool operator == (const int &pos){
        return (this->posx == pos);
    }
};

int main(){
	vector <edge_str> arr;
    arr.push_back({5,7});
    arr.push_back({10,9});
    arr.push_back({6,8});
    edge_str x;
	x.posx=5;
	x.posy=7;
	//1.查找结构体x是否存在于arr中
	vector<edge_str>::iterator it1;
	it1=find(arr.begin(),arr.end(),x);
	if(it1!=arr.end()){
		cout<<"Find!"<<endl;
	}
	else
		cout<<"Not find!"<<endl;
	//2.查找数值pos是否存在于arr的posx中
	vector<edge_str>::iterator it2;
	int pos=5;
	it2=find(arr.begin(),arr.end(),pos);
	if(it2!=arr.end()){
		cout<<"Find!"<<endl;
	}
	else
		cout<<"Not find!"<<endl;
}
