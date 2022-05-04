#include<iostream>
using namespace std;
void closure(int matrix[][100],int size){
    for(int j=0;j<size;j++){
        for(int i=0;i<size;i++){
            if(matrix[i][j]==1){
                for(int k=0;k<size;k++){
                    matrix[i][k]=matrix[j][k]||matrix[i][k];
                }
            }
        }
    }
}

int main(){
    int t;
    cin>>t;
    for(int m=0;m<t;m++){
        int flag=1;
        int mat[100][100]={0};
        int nodenum,edgenum;
        cin>>nodenum>>edgenum;
        for(int i=0;i<edgenum;i++){
            int j,k;
            cin>>j>>k;
            mat[j-1][k-1] = 1;
            mat[k-1][j-1] = 1;
            mat[i-1][i-1] = 1;
        }
        if(nodenum-edgenum!=1){
            flag=0;
        }
        closure(mat,nodenum);
        for(int j=0;j<nodenum;j++){
            for(int k=0;k<nodenum;k++){
                if(mat[j][k]!=1){
                    flag=0;
                }
            }
        }
        if(flag==0)cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
}