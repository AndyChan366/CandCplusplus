#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10000
typedef struct{
    int row,col,e;
}Triple;
typedef struct{
    Triple data[MAXSIZE+1];
    int m,n,len;
}TSMatrix;
void InitTriple(TSMatrix *Q){
    Q->m=100;
    Q->n=100;
    Q->len=0;
}
void EnterTriple(TSMatrix *Q,int row,int col,int e){
    Q->len++;
    Q->data[Q->len].row=row;
    Q->data[Q->len].col=col;
    Q->data[Q->len].e=e;
}
void PutTriple(TSMatrix *Q){
    int i;
    for(i=1;i<Q->len;i++){
        printf("%d %d %d\n",Q->data[i].row,Q->data[i].col,Q->data[i].e);
    }
    printf("%d %d %d",Q->data[i].row,Q->data[i].col,Q->data[i].e);
}
void SumTriple(TSMatrix *A,TSMatrix *B,TSMatrix *C){
    int i=1,j=1;
    while(i<=A->len&&j<=B->len){
        if(A->data[i].row<B->data[j].row){
            EnterTriple(C,A->data[i].row,A->data[i].col,A->data[i].e);
            i++;
        }
        else if(A->data[i].row==B->data[j].row){
            if(A->data[i].col<B->data[j].col){
                EnterTriple(C,A->data[i].row,A->data[i].col,A->data[i].e);
                i++;
            }
            else if(A->data[i].col>B->data[j].col){
                EnterTriple(C,B->data[j].row,B->data[j].col,B->data[j].e);
                j++;
            }
            else{
                if(B->data[j].e+A->data[i].e!=0)
                    EnterTriple(C,B->data[j].row,B->data[j].col,B->data[j].e+A->data[i].e);
                i++;
                j++;
            }
        }
        else{
            EnterTriple(C,B->data[j].row,B->data[j].col,B->data[j].e);
            j++;
        }
    }
    while(i<=A->len){
        EnterTriple(C,A->data[i].row,A->data[i].col,A->data[i].e);
        i++;
    }
    while(j<=B->len){
        EnterTriple(C,B->data[j].row,B->data[j].col,B->data[j].e);
        j++;
    }
}
int main(){
    int n,m,i,row,col,e,h,l;
    TSMatrix A,B,C;
    scanf("%d%d%d%d",&h,&l,&n,&m); 
    InitTriple(&A);
    InitTriple(&B);
    InitTriple(&C);
    for(i=0;i<n;i++){
        scanf("%d%d%d",&row,&col,&e);
        EnterTriple(&A,row,col,e);
    }
    for(i=0;i<m;i++){
        scanf("%d%d%d",&row,&col,&e);
        EnterTriple(&B,row,col,e);
    }
    SumTriple(&A,&B,&C);
    PutTriple(&C);
    return 0;
}

