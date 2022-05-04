#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
int main(){
	int a,b,num;
	cin>>a>>b>>num;
	int m[a],n[b]/*,d[a*b][3]*/;
	int **d=new int*[a*b];
	for(int i=0;i<a*b;i++){
		d[i]=new int[3];
	}
	for(int i=0;i<a;i++){
		cin>>m[i];
	}
	for(int i=0;i<b;i++){
		cin>>n[i];
	}
	int k=0;
	for(int i=0;i<a;i++){
		for(int j=0;j<b;j++){
			d[k][0]=m[i];
			d[k][1]=n[j];
			d[k][2]=m[i]+n[j];
			k++;
		}
    }
    for(int i=0;i<a*b;i++)
		for(int j=i+1;j<a*b;j++){
			if(d[i][2]>d[j][2])
				swap(d[i],d[j]);
			else if(d[i][2]==d[j][2]){
				int ll=0,rr=0,k=0;
				while(k< 3&& ll==rr){					
					ll+=d[i][k];
					rr+=d[j][k];
					if(ll>rr){
						swap(d[i],d[j]);
						break;
					}
					k++;
				}
			}		
		}
		for(int i=0;i<num;i++){
            for(int j=0;j<2;j++){
        cout<<d[i][j]<<" ";
    }
    cout<<endl;
}
}

