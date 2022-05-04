#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
bool canPlaceFlowers(vector<int>& flowerbed, int n){
    if(flowerbed.empty())return false;
    flowerbed.insert(flowerbed.begin(),0);
    flowerbed.push_back(0);
    int m=0;
    for(int i=0;i<flowerbed.size()-2;i++)
    {
        if(flowerbed[i]==0&&flowerbed[i+1]==0&&flowerbed[i+2]==0)
        {
            m++;
            i++;
        }
    }
    return m>=n;
}


int main(){
	int m;
    cin>>m;
    vector<int> flowerbed(m);
    for(int i=0;i<m;i++){
    	cin>>flowerbed[i];
	}
	int n;
	cin>>n;
    cout<<canPlaceFlowers(flowerbed,n);
    }




