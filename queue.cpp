#include<iostream>
#include<string>
#include<deque>
using namespace std;

int arr0[4][24];

void fun(int *arr,int n,deque<int> num){
	int arr1[4],arr2[4],arr3[4],arr4[4];
	int i=0;
	for(;i<4;i++){
		arr1[i]=arr[i];
		arr2[i]=arr[i];
		arr3[i]=arr[i];
		arr4[i]=arr[i];
	}
	
	if(arr[3] != 0){
		int diff=1;
		for(int i=0;i<24;i++){
			if(arr0[0][i]==arr[0] && arr0[1][i]==arr[1]  && arr0[2][i]==arr[2]  && arr0[3][i]==arr[3] ){
				diff=0;
				break;
			}
		}
		int i=0;
		for(;i<24;i++){
			if(arr0[0][i]==0)break;
		}
		if(diff){
			arr0[0][i]=arr[0];arr0[1][i]=arr[1];arr0[2][i]=arr[2];arr0[3][i]=arr[3];
		}
		return;
	}
	/*
	if(n<5){
		num.push_front(n);
		fun(arr1,n+1,num); 
		num.pop_front();
	}
	*/
	if(n<5){	
		num.push_back(n);
		fun(arr2,n+1,num); 
		num.pop_back();
	}

	if(!num.empty()){
		int i=0;
		for(;i<4;i++){
			if(arr3[i]==0)break;
		}
		arr3[i]=num.front();
		num.pop_front();
		fun(arr3,n,num); 
		num.push_front(arr3[i]);
	}
	
	if(!num.empty()){
		int i=0;
		for(;i<4;i++){
			if(arr4[i]==0)break;
		}
		arr4[i]=num.back();
		num.pop_back();
		fun(arr4,n,num); 
		num.push_back(arr4[i]);
	}
	
	return;
}

int main(){
	deque<int> num;
	int arr[4]={0,0,0,0};
	for(int i=0;i<4;i++){
		for(int j=0;j<24;j++){
			arr0[i][j]=0;
		}
	}
	
	fun(arr,1,num);
	
	for(int i=0;i<24;i++){
		cout<<arr0[0][i]<<arr0[1][i]<<arr0[2][i]<<arr0[3][i]<<endl;
	}
	
}

