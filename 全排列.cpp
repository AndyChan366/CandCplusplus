#include<iostream>
#include<cstdio>
using namespace std;
#define Maxsize 10000
int a[Maxsize];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        a[i]=i+1;
        printf("%d",a[i]);
    }
     printf("\n");   
    while(next_permutation(a,a+n)){
        for(int i=0;i<n;i++){
            printf("%d",a[i]);
}
        printf("\n");
    }
    return 0;
}

