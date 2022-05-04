#include<iostream>
#include<iomanip>
using namespace std;
const int MAX=99999999;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		int num[201][201];
		for(int p=1;p<=n;p++){
            for(int l=1;l<=n;l++){
				num[p][l]=MAX;
				if(p==l)num[p][l]=0;
			}
        }
		int i,j,k;
		for(int p=0;p<m;p++){
			cin>>i>>j>>k;
			if(k<num[i][j])num[i][j]=num[j][i]=k;
		} 
		for(k=1;k<=n;k++){
			for(i=1;i<=n;i++){
				for(j=1;j<=n;j++){
					if(num[i][k]+num[k][j]<num[i][j])num[i][j]=num[i][k]+num[k][j];
				}
			}	
		}
		if(num[1][n]==MAX)cout<<-1<<endl;
		else cout<<num[1][n]<<endl;	
	}
}