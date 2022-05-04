#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXN = 100001;
int heap[MAXN];
void downAdjust(int low,int high){
    int i=low,j=i*2;
    while(j<=high){
        if(j+1<=high&&heap[j+1]<heap[j]){
            j=j+1;
        }
        if(heap[j]<heap[i]){
            swap(heap[j],heap[i]);
            i=j;
            j=i*2;
        }
		else{
            break;
        }
    }
}


void upAdjust(int low,int high){
    int i=high,j=i/2;
    while(j>=low){
        if(heap[j]>heap[i]){
            swap(heap[j],heap[i]);
            i=j;
            j=i/2;
        }
		else{
            break;
        }
    }
}


int main(){
	int t,n,e;
	cin>>t;
	for(int T=0;T<t;T++){
		cin>>n;
		for(int i=1;i<=n;++i){
			cin>>heap[i];
		}
		int temp=heap[1];
		swap(heap[1],heap[n--]);
		downAdjust(1,n);
		upAdjust(1,n);
		for(int i=1;i<=n;++i){
			cout<<heap[i]<<" ";
		}
		cout<<temp<<endl;
	}
    return 0;
}