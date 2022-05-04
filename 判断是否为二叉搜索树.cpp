/*给定前序遍历和中序遍历判断该树是否为二叉搜索树。
输入：
第一行为样例个数，接下来依次为节点个数、前序遍历、中序遍历。
输出：
Yes or No。
输入样例：
2
2
1 3
3 1
3
2 1 3
1 2 3
输出样例：
No
Yes*/
#include <iostream>
using namespace std;
bool ans=false;
 
bool preorder(int sequence[],int start,int end){
	if(NULL==sequence||start>end){
		ans=true;
		return false;
	}
	if(start==end)return true;
	int root=sequence[start];
	int bound=start+1;
	for(bound;bound<=end;bound++){
		if(sequence[bound]>root)break;
	}
	int i=bound;
	for(i;i<=end;i++){
		if(sequence[i]<root)return false;
	}
	bool left=true;
	bool right=true;
	if(bound>start+1)left=preorder(sequence,start+1,bound-1);
	if(bound<=end)right=preorder(sequence,bound,end);
	return left&&right;
}

bool midorder(int sequence[],int start,int end){
	if(NULL==sequence||start>end){
		ans=true;
		return false;
	}
	if(start==end)return true;
	int mid=end-((end-start)>>1);
	int midValue=sequence[mid];
	int i,j;
	for(i=0;i<mid;i++){
		if(sequence[i]>midValue)return false;
	}
	for(j=mid+1;j<=end;j++){
		if(sequence[j]<midValue)return false;
	}
	int left=true;
	int right=true;
	if(mid>start)left=midorder(sequence,start,mid-1);
	if(mid<end)right=midorder(sequence,mid+1,end);
	return left&&right;
}
 
int main(){
    int n;
    cin>>n;
    for(int j=0;j<n;j++){
        int len;
        cin>>len;
        int sequence1[len];
        int sequence2[len];
        for(int i=0;i<len;i++){
            cin>>sequence1[i];
        }
        for(int i=0;i<len;i++){
            cin>>sequence2[i];
        }
        bool result1=preorder(sequence1,0,len-1);
        bool result2=midorder(sequence2,0,len-1);
        if(result1&&result2)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
	return 0;
}



 
