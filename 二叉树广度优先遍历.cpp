/*二叉树的广度优先遍历。
输入：
输入包括两行，分别为一颗二叉树的先序遍历序列s1，和其中序遍历序列s2，序列只包含大写字母，并且每个字母最多只会出现一次。
输出：
请输出该二叉树的广度优先遍历序列。
输入样例：
DBACEGF
ABCDEFG
输出样例：
DBEACGF*/
/***********************************************************
* 已知树的先序遍历和中序遍历，输出该树的广度优先遍历；
* 解决方案是，先重建这颗树：先求出中序遍历字符串的长度，定义一个Map 类型
* 将中序字符串的每个字母和它在字符串中的位置存到Map中，如：中序字符串为ABC，
* 那么将 0-A、1-B、2-C分别存进Map中；
* 之后用先序字符串来重建树：
* 1、从先序字符串的第一个字母开始，并在中序字符串中找到它的位置
* 2、按照二叉树的排序原则将它插入树中，插入原则，按照字母在中序位置的大小来插；
* 重复1、2直到最后一个字母插入；
* 至此，树已经重建好，广度优先遍历，需创建一个queue，借助队列数据结构，
* 由于队列是先进先出的顺序，因此可以先将左子树入队，然后再将右子树入队。
*这样一来，左子树结点就存在队头，可以先被访问到
*最后输出队列中front的字母就可以了
*************************************************************/
#include <iostream>
#include <string>
#include <queue>
using namespace std;
 
bool temp=true;
struct Map{
	int value;
	char data;
	Map(){
		value=NULL;
		data=NULL;
	}
}m[1000];

struct binarytree{
	binarytree *left, *right;
	int v;
	char ch;
	binarytree(){
		left=NULL;
		right=NULL;
	}
}*sub_root, *first;

void Insert(binarytree *&sub_root,int d,char c){
	if(sub_root==NULL){
		sub_root=new binarytree; 
		sub_root->v=d;
		sub_root->ch=c;
		if(temp){
			first=sub_root;
			temp=false;
		}
	}
	else if(d<sub_root->v){
		return Insert(sub_root->left,d,c);
    }
	else return Insert(sub_root->right,d,c);
}
 
/*void inorder(binarytree *sub_root){
    // 后序遍历
	if(sub_root!=NULL){
		inorder(sub_root->left);
		inorder(sub_root->right);
		cout<<sub_root->v<<sub_root->ch<<" ";
	}
}*/

void layertraverse(binarytree *sub_root){
	queue<binarytree *> q;
	q.push(sub_root);
	binarytree * temp_node;
	while(!q.empty()){
		temp_node=q.front();
		cout<<temp_node->ch;
		q.pop();
		if(temp_node->left!=NULL)q.push(temp_node->left);
		if(temp_node->right!=NULL)q.push(temp_node->right);
	}
}

int main(){
	string s1,s2;
    temp=true;
    sub_root=NULL;
    first=NULL;
    cin>>s1;
    cin>>s2;
    int len=s1.length();
    for(int i=0;i<len;i++){
        m[i].value=i;
        m[i].data=s2[i];
    }
    for(int i=0;i<len;i++){
        char temp=s1[i];
        int k=s2.find(temp);
        Insert(first,m[k].value,m[k].data);
    }
    layertraverse(first);
	return 0;
} 