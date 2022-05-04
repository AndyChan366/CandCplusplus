/*现在给出一棵二叉树，希望你找出它的一棵子树，该子树为对称二叉树，且节点数最多。请输出这棵子树的节点数。
输入格式：
第一行一个正整数n，表示给定的树的节点的数目，规定节点编号1∼n，其中节点1是树根。
第二行n个正整数，用一个空格分隔，第i个正整数v_i代表节点i的权值。
接下来n行，每行两个正整数l_i, r_i，分别表示节点i的左右孩子的编号。如果不存在左右孩子，则以-1表示。两个数之间用一个空格隔开。
输出格式：
共一行，包含一个整数，表示给定的树的最大对称二叉子树的节点数。
输入样例：
2
1 3
2 -1
-1 -1
输出样例：
1
*/
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
#define SIZE 10000
int n,sum=1,ans=1;
bool F=true;

struct Tree{
	int v;
    int lchild;
    int rchild;
}tree[SIZE];
 
void DFS(int L,int R){
	if(F==false) return;
	if(L==-1 && R==-1) return;
	if((L==-1 && R!=-1) || (L!=-1 && R==-1)){
		F=false;
		return;
	}
	if(tree[L].v==tree[R].v){
		sum+=2;
		DFS(tree[L].lchild,tree[R].rchild);
		DFS(tree[L].rchild,tree[R].lchild);
	}
	else{
		F=false;
		return;
	}
}
 
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
        scanf("%d",&tree[i].v);
    } 
	for(int i=1;i<=n;i++){
        scanf("%d%d",&tree[i].lchild,&tree[i].rchild);
    }
	for(int i=1;i<=n;i++){
		F=true;
		sum=1;
		DFS(tree[i].lchild,tree[i].rchild);
		if(F)ans=max(ans,sum);
	}
	cout<<ans;
	return 0;
}
 
