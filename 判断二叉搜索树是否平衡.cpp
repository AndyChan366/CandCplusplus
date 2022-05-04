/*给定一颗二叉查找树，其中结点上存储整数关键字，请你判断它是否一棵平衡的二叉查找树。
输入：
第一行是测试样例数，接下来是若干测试样例；
对于每个测试样例，第一行是二叉树结点个数n，第二行是n个关键字序列，表示二叉树的先序遍历结果。假定关键字均不相同。
输出：
如果二叉查找树是平衡的，则输出YES，否则输出NO，每个输出占一行。
输入样例：
5
2
10 5
3
1 4 7
3 
5 3 2
3
10 4 23
5
10 6 5 8 20
输出样例：
YES
NO
NO
YES
YES*/
#include<iostream>
#include<vector>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};
class Solution{
    public:
    TreeNode* TreeConstruction(vector<int> v){
        if(v.size()==0)return NULL;
        TreeNode* root=new TreeNode(v.front());
        if(v.size()==1)return root;
        else{
            TreeNode* tmp=root;
            for(int i=1;i<v.size();i++){
                tmp=root;
                while(1){
                    if(v[i]<tmp->val){
                        if(tmp->left==NULL){
                            TreeNode* newnode=new TreeNode(v[i]);
                            tmp->left=newnode;
                            break;
                        }
                        else if(tmp->left!=NULL){
                            tmp=tmp->left;
                        }
                    }
                    else if(v[i]>=tmp->val){
                        if(tmp->right==NULL){
                            TreeNode* newnode=new TreeNode(v[i]);
                            tmp->right=newnode;
                            break;
                        }
                        else if(tmp->right!=NULL){
                            tmp=tmp->right;
                        }
                    }
                }
            }
        }
        return root;
    }
    int depth(TreeNode* root){
       return (root==NULL?0:max(depth(root->left),depth(root->right))+1);
    }
    bool isBalanced(TreeNode* root){
        if(root==NULL)return true;
        return (isBalanced(root->right)&&isBalanced(root->left)&&(abs(depth(root->left)-depth(root->right))<=1));
    }
};
int main(){
    int N,len,num;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>len;
        vector<int> v;
        for(int i=0;i<len;i++){
            cin>>num;
            v.push_back(num);
        }
        Solution s;
        TreeNode* searchTree=s.TreeConstruction(v);
        if(s.isBalanced(searchTree)==true)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}